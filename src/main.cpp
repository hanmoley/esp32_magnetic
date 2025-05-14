#include <Arduino.h>
#include <micro_ros_platformio.h>
#include <WiFi.h>

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <std_msgs/msg/int32.h>
#include <std_msgs/msg/float32.h>
#include <std_msgs/msg/float32_multi_array.h>

#include <example_interfaces/srv/add_two_ints.h>

#include <TimeLib.h>    //add the time library

#include <sensor_msgs/msg/laser_scan.h>
#include <micro_ros_utilities/string_utilities.h>

#include <ESP32Servo.h>  //舵机
#include "Adafruit_MLX90393.h"
#include <sensor_msgs/msg/magnetic_field.h>
#include <builtin_interfaces/msg/time.h>

#include "Adafruit_Sensor_Calibration.h"
// select either EEPROM or SPI FLASH storage:
#ifdef ADAFRUIT_SENSOR_CALIBRATION_USE_EEPROM
  Adafruit_Sensor_Calibration_EEPROM cal;
#else
  Adafruit_Sensor_Calibration_SDFat cal;
#endif

// 调试开关
#define DEBUG_MODE 0  // 设置为1开启调试，0关闭调试

/*****************MLX90393***********/
// 定义四个传感器对象和地址数组
#define SENSOR_COUNT 4
Adafruit_MLX90393 sensors[SENSOR_COUNT];
uint8_t sensor_addresses[SENSOR_COUNT] = {0xC, 0xD, 0xE, 0xF};
#define MLX90393_CS 10
/************************************/

// 采样率监控
unsigned long sample_counts[SENSOR_COUNT] = {0};
unsigned long last_report_time = 0;

// 添加互斥锁保护I2C通信
SemaphoreHandle_t i2c_mutex;

rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;

// 全局标志，控制传感器读取
volatile bool sensorReadActive = false;

/*sync time*/
const int timeout_ms = 1000;
static int64_t time_ms;
static time_t time_seconds;
char time_str[25];


/* node */
rcl_node_t node;

/* magnetic_publisher */
rcl_publisher_t magnetic_publishers[SENSOR_COUNT];
rcl_timer_t magnetic_timers[SENSOR_COUNT];
// 每个传感器一个标准磁场消息
sensor_msgs__msg__MagneticField mag_msgs[SENSOR_COUNT];

// 提前声明统一的读取和发布函数
void read_and_publish_sensor(int sensor_index) {
  // 简化防止重入逻辑
  if (sensorReadActive) {
    #if DEBUG_MODE
      Serial.print("Sensor "); Serial.print(sensor_index);
      Serial.println(" read busy, skipping...");
    #endif
    return;
  }
  
  sensorReadActive = true;
  
  if (xSemaphoreTake(i2c_mutex, pdMS_TO_TICKS(20)) == pdTRUE) {
    sensors_event_t event;
    
    // 简化读取逻辑
    if (sensors[sensor_index].getEvent(&event)) {
      // 填充磁场数据
      mag_msgs[sensor_index].magnetic_field.x = event.magnetic.x + 20;
      mag_msgs[sensor_index].magnetic_field.y = event.magnetic.y - 45;
      mag_msgs[sensor_index].magnetic_field.z = event.magnetic.z + 67;
      
      // 添加时间戳
      int64_t current_time = rmw_uros_epoch_millis();
      mag_msgs[sensor_index].header.stamp.sec = current_time / 1000;
      mag_msgs[sensor_index].header.stamp.nanosec = (current_time % 1000) * 1000000;
      
      // 发布消息
      rcl_publish(&magnetic_publishers[sensor_index], &mag_msgs[sensor_index], NULL);
      
      // 增加计数器
      sample_counts[sensor_index]++;
      
      // 每5秒报告一次采样率
      unsigned long now = millis();
      if (now - last_report_time > 5000) {
        #if DEBUG_MODE
          for (int i = 0; i < SENSOR_COUNT; i++) {
            float rate = sample_counts[i] / 5.0;  // 5秒内的平均采样率
            Serial.print("传感器 "); Serial.print(i); 
            Serial.print(" 采样率: "); Serial.print(rate); Serial.println(" Hz");
            sample_counts[i] = 0;
          }
        #endif
        last_report_time = now;
      }
    } else {
      #if DEBUG_MODE
        Serial.print("传感器 "); Serial.print(sensor_index);
        Serial.println(" 读取失败");
      #endif
    }
    
    xSemaphoreGive(i2c_mutex);
  } 
  #if DEBUG_MODE
  else {
    Serial.print("无法获取I2C互斥锁，传感器 "); 
    Serial.println(sensor_index);
  }
  #endif
  
  sensorReadActive = false;
}

// 每个传感器的回调函数
void timer_mag_callback_0(rcl_timer_t *timer, int64_t last_call_time) {
  if (timer == NULL) return;
  #if DEBUG_MODE
    Serial.println("timer_mag_callback_0");
  #endif
  read_and_publish_sensor(0);
}

void timer_mag_callback_1(rcl_timer_t *timer, int64_t last_call_time) {
  if (timer == NULL) return;
  #if DEBUG_MODE
    Serial.println("timer_mag_callback_1");
  #endif
  read_and_publish_sensor(1);
}

void timer_mag_callback_2(rcl_timer_t *timer, int64_t last_call_time) {
  if (timer == NULL) return;
  #if DEBUG_MODE
    Serial.println("timer_mag_callback_2");
  #endif
  read_and_publish_sensor(2);
}

void timer_mag_callback_3(rcl_timer_t *timer, int64_t last_call_time) {
  if (timer == NULL) return;
  #if DEBUG_MODE
    Serial.println("timer_mag_callback_3");
  #endif
  read_and_publish_sensor(3);
}

// ROS通信任务，在第二个核心上运行
void rosSpinTask(void *pvParameters) {
  while(1) {
    rclc_executor_spin_some(&executor, RCL_MS_TO_NS(10));
    vTaskDelay(pdMS_TO_TICKS(5)); // 短暂延时
  }
}

void setup()
{
  Serial.begin(115200); // for the serial print
  /* set the communication method */
  
  // 等待串口准备好
  delay(1000);
  #if DEBUG_MODE
    Serial.println("Starting setup...");
  #endif
  
  // 创建互斥锁
  i2c_mutex = xSemaphoreCreateMutex();
  if (i2c_mutex == NULL) {
    Serial.println("Failed to create i2c mutex");
    return;
  }

  // set wifi for communicate with the MicroROS
  IPAddress agent_ip;
  agent_ip.fromString("192.168.1.116");
  //set wifi name, secret code, computer IP, port
  set_microros_wifi_transports("smart", "smartsmart", agent_ip, 8888);

  // 延时时一段时间，等待设置完成
  delay(2000);

  // 初始化内存分配器
  allocator = rcl_get_default_allocator();
  // 创建初始化选项
  rclc_support_init(&support, 0, NULL, &allocator);

  //create the esp32_node
  rclc_node_init_default(&node, "esp32_node", "", &support);

  /* 创建执行器 - 增加任务数量 */
  rclc_executor_init(&executor, &support.context, 10, &allocator);

  /* 设置定时器超时时间 - 30Hz 约等于 33ms */
  const unsigned int timer_timeout = 33;  // 33ms ≈ 30Hz

  /* magnetic_publisher init*/
  /**************************this is for MLX90393**********************************/
  // 回调函数指针数组
  void (*timer_callbacks[SENSOR_COUNT])(rcl_timer_t*, int64_t) = {
    timer_mag_callback_0,
    timer_mag_callback_1,
    timer_mag_callback_2,
    timer_mag_callback_3
  };

  // 为每个传感器初始化消息和发布者
  for (int i = 0; i < SENSOR_COUNT; i++) {
    // 初始化标准磁场消息
    sensor_msgs__msg__MagneticField__init(&mag_msgs[i]);
    
    // 正确初始化frame_id
    mag_msgs[i].header.frame_id = micro_ros_string_utilities_set(mag_msgs[i].header.frame_id, "map");
    
    // 创建topic名称
    char topic_name[30];
    sprintf(topic_name, "magnetic_sensor_%d", i);
    
    // 初始化发布者
    rclc_publisher_init_default(
      &magnetic_publishers[i],
      &node,
      ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, MagneticField),
      topic_name);
      
    // 初始化定时器 - 错开启动时间，避免同时触发
    // 给不同传感器设置明显不同的时间间隔，避免同时触发
    unsigned int timer_offset = timer_timeout + (i * 5); // 错开5ms
    
    rclc_timer_init_default(
      &magnetic_timers[i],
      &support,
      RCL_MS_TO_NS(timer_offset),
      timer_callbacks[i]);
      
    // 添加定时器到执行器
    rclc_executor_add_timer(&executor, &magnetic_timers[i]);
    delay(50); // 添加短延时
  }

  // I2C初始化和扫描
  #if DEBUG_MODE
    Serial.println("扫描I2C设备...");
  #endif
  
  // 安全地初始化I2C
  if (xSemaphoreTake(i2c_mutex, portMAX_DELAY) == pdTRUE) {
    Wire.begin(21, 22, 400000); // 保持400kHz的I2C速率
    
    #if DEBUG_MODE
      for (byte addr = 1; addr < 127; addr++) {
        Wire.beginTransmission(addr);
        if (Wire.endTransmission() == 0) {
          Serial.print("在地址0x"); Serial.print(addr, HEX); Serial.println("发现设备");
        }
      }
    #endif
    
    xSemaphoreGive(i2c_mutex);
  }

  #if DEBUG_MODE
    Serial.println("启动多MLX90393传感器");
  #endif

  // 初始化每个传感器
  bool all_sensors_initialized = true;
  
  if (xSemaphoreTake(i2c_mutex, portMAX_DELAY) == pdTRUE) {
    for (int i = 0; i < SENSOR_COUNT; i++) {
      if (!sensors[i].begin_I2C(sensor_addresses[i])) {
        Serial.print("传感器 "); Serial.print(i); 
        Serial.print(" (地址0x"); Serial.print(sensor_addresses[i], HEX);
        Serial.println(") 未找到...请检查接线？");
        all_sensors_initialized = false;
      } else {
        #if DEBUG_MODE
          Serial.print("找到MLX90393传感器 "); Serial.print(i);
          Serial.print(" (地址0x"); Serial.print(sensor_addresses[i], HEX); Serial.println(")");
        #endif
        
        // 配置传感器 - 使用中等设置平衡精度和速度
        sensors[i].setGain(MLX90393_GAIN_1X);
        sensors[i].setResolution(MLX90393_X, MLX90393_RES_16);
        sensors[i].setResolution(MLX90393_Y, MLX90393_RES_16);
        sensors[i].setResolution(MLX90393_Z, MLX90393_RES_16);
        sensors[i].setOversampling(MLX90393_OSR_2);  // 中等过采样
        sensors[i].setFilter(MLX90393_FILTER_3);     // 中等滤波
        
        #if DEBUG_MODE
          // 记录并打印增益设置
          Serial.print("传感器 "); Serial.print(i); Serial.print(" 增益设置为: ");
          switch (sensors[i].getGain()) {
            case MLX90393_GAIN_1X: Serial.println("1 x"); break;
            case MLX90393_GAIN_1_33X: Serial.println("1.33 x"); break;
            case MLX90393_GAIN_1_67X: Serial.println("1.67 x"); break;
            case MLX90393_GAIN_2X: Serial.println("2 x"); break;
            case MLX90393_GAIN_2_5X: Serial.println("2.5 x"); break;
            case MLX90393_GAIN_3X: Serial.println("3 x"); break;
            case MLX90393_GAIN_4X: Serial.println("4 x"); break;
            case MLX90393_GAIN_5X: Serial.println("5 x"); break;
          }
        #endif
      }
    }
    xSemaphoreGive(i2c_mutex);
  }

  if (!all_sensors_initialized) {
    Serial.println("警告：一些传感器初始化失败");
  } else {
    #if DEBUG_MODE
      Serial.println("所有传感器初始化成功");
    #endif
  }

  /* syc time */
  /*=========================同步时间=====================================*/
  while (!rmw_uros_epoch_synchronized()) // 判断时间是否同步
  {
    rmw_uros_sync_session(timeout_ms); //  同步时间
    if (rmw_uros_epoch_synchronized())
    {
      time_ms = rmw_uros_epoch_millis(); // 获取当前时间
      time_seconds = time_ms / 1000;
      setTime(time_seconds + 8 * 3600); // 将当前时间+8H到北京时间然后设置到系统
    }
    delay(10);
  }
  
  sprintf(time_str, "%04d-%02d-%02d %02d:%02d:%02d ", year(), month(), day(), hour(), minute(), second());
  #if DEBUG_MODE
    Serial.println(time_str);
  #endif

  // 在第二个核心上创建ROS通信任务
  xTaskCreatePinnedToCore(
    rosSpinTask,
    "ROSSpinTask",
    8192,
    NULL,
    2,
    NULL,
    1  // 在核心1上运行
  );
  
  // 设置采样率监控的初始时间
  last_report_time = millis();
}

void loop()
{
  // 由于ROS通信任务已经移到第二个核心，主循环可以更加轻松
  // 只需处理非ROS相关的任务或监控系统状态
  
  // 检查是否需要输出采样率报告
  unsigned long now = millis();
  if (now - last_report_time > 5000 && DEBUG_MODE) {
    for (int i = 0; i < SENSOR_COUNT; i++) {
      float rate = sample_counts[i] / 5.0;
      Serial.print("传感器 "); Serial.print(i);
      Serial.print(" 采样率: "); Serial.print(rate); Serial.println(" Hz");
      sample_counts[i] = 0;
    }
    last_report_time = now;
  }
  
  delay(100); // 主循环可以使用较长的延时，节省能源
}