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

/*****************MLX90393***********/
Adafruit_MLX90393 sensor = Adafruit_MLX90393();
#define MLX90393_CS 10
/************************************/

#define MAX_CHANNEL 4

#define PCOUNT 10
#define Trig 27 // 设定SR04连接的Arduino引脚
#define Echo 21

#define DMA_BUFFER_SIZE 1024

// DMA缓冲区
uint8_t dma_buffer[DMA_BUFFER_SIZE];
rclc_executor_t executor;
rclc_support_t support;
rcl_allocator_t allocator;


/* 舵机 */
Servo servo1;
bool connected_agent = false;

/*sync time*/
const int timeout_ms = 1000;
static int64_t time_ms;
static time_t time_seconds;
char time_str[25];


/* node */
rcl_node_t node;

/* pressure_publisher */
rcl_publisher_t sensor_publisher;
rcl_timer_t timer1;
// declare the publish message
std_msgs__msg__Float32MultiArray multisensor_msg;
// define the timer to receive callback function
void timer1_callback(rcl_timer_t *timer, int64_t last_call_time)
{
  if (timer == NULL) return;
  
  // 快速读取多路ADC并填充数据
  bool bit0, bit1;
  for (int i = 0; i < MAX_CHANNEL; i++) {
    bit0 = (i >> 0) & 1;
    bit1 = (i >> 1) & 1;
    
    // 直接设置引脚，不使用digitalWrite以提高速度
    if (bit0) {
      GPIO.out_w1ts = (1 << 25);
    } else {
      GPIO.out_w1tc = (1 << 25);
    }
    
    if (bit1) {
      GPIO.out_w1ts = (1 << 26);
    } else {
      GPIO.out_w1tc = (1 << 26);
    }
    
    // 极短时间稳定
    delayMicroseconds(100);
    
    // 读取ADC值
    int analogValue = analogRead(34);
    float realVolts = (3.3 * analogValue) / 4095;
    multisensor_msg.data.data[i] = realVolts;
  }
  
  // 发布消息
  rcl_publish(&sensor_publisher, &multisensor_msg, NULL);
}

/* magnetic_publisher */
rcl_publisher_t magnetic_publisher;
rcl_timer_t timer_magnetic;
// declare the publish message
sensor_msgs__msg__MagneticField mag_msg;
// std_msgs__msg__Float32MultiArray mag_msg;
// define the timer to receive callback function
void timer_mag_callback(rcl_timer_t *timer, int64_t last_call_time)
{
  if (timer == NULL) return;
  // 读取磁场传感器
  sensors_event_t event;
  if (sensor.getEvent(&event)) {
    // 填充ROS消息
    mag_msg.magnetic_field.x = event.magnetic.x + 20;
    mag_msg.magnetic_field.y = event.magnetic.y - 45;
    mag_msg.magnetic_field.z = event.magnetic.z + 67;
    
    // 添加时间戳
    int64_t current_time = rmw_uros_epoch_millis();
    mag_msg.header.stamp.sec = current_time / 1000;
    mag_msg.header.stamp.nanosec = (current_time % 1000) * 1000000;

    // 设置frame_id - 添加这一行
    snprintf(mag_msg.header.frame_id.data, sizeof(mag_msg.header.frame_id.data), "map");
    mag_msg.header.frame_id.size = strlen(mag_msg.header.frame_id.data);
    
    // 发布消息
    rcl_publish(&magnetic_publisher, &mag_msg, NULL);
  }
}

/* battery_publisher */
rcl_publisher_t battery_publisher;
rcl_timer_t timer2;
// declare the publish message
std_msgs__msg__Float32 pub_battery_msg;
// define the timer to receive callback function
void timer2_callback(rcl_timer_t *timer, int64_t last_call_time)
{
  if (timer == NULL) return;
  
  // 读取电池电压
  int analogValue = analogRead(35);
  float voltage = (3.3 * analogValue) / 4095 * (10.0 + 18.0) / 18.0; // 假设有分压电路
  pub_battery_msg.data = voltage;
  
  // 发布消息
  rcl_publish(&battery_publisher, &pub_battery_msg, NULL);
}

/* publisher_laser */
//declare the publisher of topic
rcl_publisher_t laser_publisher;
//declare the publish message
sensor_msgs__msg__LaserScan pub_laser_msg;

/* subscriber1 */
rcl_subscription_t led_ctrl_subcriber;
// set the messege
std_msgs__msg__Int32 sub_msg;
//define the callback function of receive topic 
void callback_led_ctrl_subscription(const void *msgin)
{
  Serial.printf("enter the callback_led_ctrl_subscription\n");
  const std_msgs__msg__Int32 *msg = (const std_msgs__msg__Int32 *)msgin;
  if (msg->data == 0) {
    GPIO.out_w1ts = (1 << 2); // 直接设置GPIO，比digitalWrite快
  } else {
    GPIO.out_w1tc = (1 << 2);
  }
}

/* add_service */
rcl_service_t add_service;
//服务请求和返回消息定义
example_interfaces__srv__AddTwoInts_Request req;
example_interfaces__srv__AddTwoInts_Response res;
//服务回调函数
void add_service_callback(const void *req, void *res)
{
  example_interfaces__srv__AddTwoInts_Request *req_in = (example_interfaces__srv__AddTwoInts_Request *)req;
  example_interfaces__srv__AddTwoInts_Response *res_in = (example_interfaces__srv__AddTwoInts_Response *)res;
  // 计算sum
  res_in->sum = req_in->a + req_in->b;
}

/**
 * @brief get the distance before laser and barrier
 * 
 * @param angle
 */
float get_distance(int angle)
{
  // 移动舵机
  servo1.write(angle);
  
  // 减少稳定时间
  delayMicroseconds(15000); // 15ms，比原来的25ms更短
  
  // 触发测距
  GPIO.out_w1tc = (1 << Trig);
  delayMicroseconds(2);
  GPIO.out_w1ts = (1 << Trig);
  delayMicroseconds(10);
  GPIO.out_w1tc = (1 << Trig);
  
  // 测量回波时间
  double mtime = pulseIn(Echo, HIGH, 25000); // 添加超时时间，避免无限等待
  
  // 如果超时，返回最大距离
  if (mtime == 0) {
    return 5.0;
  }
  
  // 计算距离（米）
  float detect_distance = mtime / 58.0 / 100.0;
  return detect_distance;
}

/**
 * @brief MicroROSTASK,打印ID
 * for another core
 *
 * @param param
 */
void microros_task(void *param)
{
  // 设置通过WIFI进行MicroROS通信
  // IPAddress agent_ip;
  // agent_ip.fromString("192.168.1.123");
  // 设置wifi名称，密码，电脑IP,端口号
  // set_microros_wifi_transports("smart", "smartsmart", agent_ip, 8888);
  // 延时时一段时间，等待设置完成
  // delay(2000);

  // 初始化内存分配器
  // allocator = rcl_get_default_allocator();
  // 创建初始化选项
  // rclc_support_init(&support, 0, NULL, &allocator);

  /* publiser_laser */
  rclc_publisher_init_default(                                           // 发布初始化
    &laser_publisher,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, LaserScan),
    "/scan");

  // 创建执行器
  // rclc_executor_init(&executor, &support.context, 4, &allocator);
  /* publiser_laer fill the data */
  pub_laser_msg.header.frame_id = micro_ros_string_utilities_set(pub_laser_msg.header.frame_id, "laser"); // 初始化消息内容
  pub_laser_msg.angle_increment = 1.0 / 180 * PI;
  pub_laser_msg.range_min = 0.05;
  pub_laser_msg.range_max = 5.0;

  while (true)
  {
    /* publiser the laser data*/
    static float ranges[PCOUNT + 1];
    for (int i = 0; i < int(180 / PCOUNT); i++)
    {
      int64_t start_scan_time = rmw_uros_epoch_millis();
      for (int j = 0; j < PCOUNT; j++)
      {
        int angle = i * 10 + j;
        ranges[j] = get_distance(angle);
      }
      pub_laser_msg.angle_min = float(i * 10) / 180 * PI;       // 结束角度
      pub_laser_msg.angle_max = float(i * (10 + 1)) / 180 * PI; // 结束角度

      int64_t current_time = rmw_uros_epoch_millis();
      pub_laser_msg.scan_time = float(current_time - start_scan_time) * 1e-3;
      pub_laser_msg.time_increment = pub_laser_msg.scan_time / PCOUNT;
      pub_laser_msg.header.stamp.sec = current_time * 1e-3;
      pub_laser_msg.header.stamp.nanosec = current_time - pub_laser_msg.header.stamp.sec * 1000;
      pub_laser_msg.ranges.data = ranges;
      pub_laser_msg.ranges.capacity = PCOUNT;
      pub_laser_msg.ranges.size = PCOUNT;
      rcl_publish(&laser_publisher, &pub_laser_msg, NULL);
      delay(10);
    }
    // rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100)); // 循环处理数据
  }

}

void setup()
{
  #if 1
  Serial.begin(115200); // for the serial print
  /* set the communication method */
  // 设置通过串口进行MicroROS通信
  // set_microros_serial_transports(Serial);

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

  /* 创建执行器 */
  rclc_executor_init(&executor, &support.context, 4, &allocator);

  /* pressure_publisher init*/
  // create the timer 200ms once sent
  const unsigned int timer_timeout = 20;
  rclc_publisher_init_default(
    &sensor_publisher,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32MultiArray),
    "presure_sensor");
  rclc_timer_init_default(
      &timer1,
      &support,
      RCL_MS_TO_NS(timer_timeout),
      timer1_callback);

    
  // add the timer to executor
  rclc_executor_add_timer(&executor, &timer1);
  // init the multiselect
  pinMode(27, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);
  // init the ADC
  pinMode(34, INPUT);
  analogSetAttenuation(ADC_11db);

  // 分配内存
  multisensor_msg.data.data = (float *)malloc(MAX_CHANNEL * sizeof(float));
  multisensor_msg.data.size = MAX_CHANNEL;
  
  // 检查内存分配是否成功
  if (multisensor_msg.data.data == NULL) {
      Serial.printf("内存分配失败！\n");
  }
  // fill the inital value 0
  for (int32_t i = 0; i < MAX_CHANNEL; i++) {
    multisensor_msg.data.data[i] = 0.0f;  // 将每个元素设置为 0
  }

  /* magnetic_publisher init*/
  /**************************this is for MLX90393**********************************/
  sensor_msgs__msg__MagneticField__init(&mag_msg);
  rclc_publisher_init_default(
    &magnetic_publisher,
    &node,
    // ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32MultiArray),
    ROSIDL_GET_MSG_TYPE_SUPPORT(sensor_msgs, msg, MagneticField),
    "magnetic_sensor");
  rclc_timer_init_default(
      &timer_magnetic,
      &support,
      RCL_MS_TO_NS(timer_timeout),
      timer_mag_callback);

  // add the timer to executor
  rclc_executor_add_timer(&executor, &timer_magnetic);
  Serial.println("Scanning I2C devices...");
  Wire.begin(21, 22);
  for (byte addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.print("Found device at 0x"); Serial.println(addr, HEX);
    }
  }
  /* Wait for serial on USB platforms. */
  while (!Serial) {
      delay(10);
  }
 
  Serial.println("Starting Adafruit MLX90393 Demo");
 
  if (! sensor.begin_I2C(0xC)) {          // hardware I2C mode, can pass in address & alt Wire
  //if (! sensor.begin_SPI(MLX90393_CS)) {  // hardware SPI mode
    Serial.println("No sensor found ... check your wiring?");
    while (1) { delay(10); }
  }
  Serial.println("Found a MLX90393 sensor");
 
  sensor.setGain(MLX90393_GAIN_1X);
  // You can check the gain too
  Serial.print("Gain set to: ");
  switch (sensor.getGain()) {
    case MLX90393_GAIN_1X: Serial.println("1 x"); break;
    case MLX90393_GAIN_1_33X: Serial.println("1.33 x"); break;
    case MLX90393_GAIN_1_67X: Serial.println("1.67 x"); break;
    case MLX90393_GAIN_2X: Serial.println("2 x"); break;
    case MLX90393_GAIN_2_5X: Serial.println("2.5 x"); break;
    case MLX90393_GAIN_3X: Serial.println("3 x"); break;
    case MLX90393_GAIN_4X: Serial.println("4 x"); break;
    case MLX90393_GAIN_5X: Serial.println("5 x"); break;
  }
 
  // Set resolution, per axis. Aim for sensitivity of ~0.3 for all axes.
  sensor.setResolution(MLX90393_X, MLX90393_RES_17);
  sensor.setResolution(MLX90393_Y, MLX90393_RES_17);
  sensor.setResolution(MLX90393_Z, MLX90393_RES_16);
 
  // Set oversampling
  sensor.setOversampling(MLX90393_OSR_3);
 
  // Set digital filtering
  sensor.setFilter(MLX90393_FILTER_5);
  // 分配内存
  // 初始化消息
  // mag_msg = sensor_msgs__msg__MagneticField__create();
  // 分配内存
  // mag_msg.data.data = (float *)malloc(3 * sizeof(float));
  // mag_msg.data.size = 3;
  
  // // 检查内存分配是否成功
  // if (mag_msg.data.data == NULL) {
  //     Serial.printf("内存分配失败！\n");
  // }
  // // fill the inital value 0
  // for (int32_t i = 0; i < 3; i++) {
  //   mag_msg.data.data[i] = 0.0f;  // 将每个元素设置为 0
  // }
  // begin calibration
  Serial.println("Calibration filesys test");
  if (!cal.begin()) {
    Serial.println("Failed to initialize calibration helper");
    while (1) yield();
  }
  Serial.print("Has EEPROM: "); Serial.println(cal.hasEEPROM());
  Serial.print("Has FLASH: "); Serial.println(cal.hasFLASH());

  if (! cal.loadCalibration()) {
    Serial.println("No calibration loaded/found... will start with defaults");
  } else {
    Serial.println("Loaded existing calibration");
  }

  // in uTesla
  cal.mag_hardiron[0] = -3.35;
  cal.mag_hardiron[1] = -0.74;
  cal.mag_hardiron[2] = -40.79;

  // in uTesla
  cal.mag_softiron[0] = 0.965;
  cal.mag_softiron[1] = 0.018;
  cal.mag_softiron[2] = 0.010;  
  cal.mag_softiron[3] = 0.018;
  cal.mag_softiron[4] = 0.960;
  cal.mag_softiron[5] = 0.003;  
  cal.mag_softiron[6] = 0.010;
  cal.mag_softiron[7] = 0.003;
  cal.mag_softiron[8] = 1.080;
  // Earth total magnetic field strength in uTesla (dependent on location and time of the year),
  // visit: https://www.ngdc.noaa.gov/geomag/calculators/magcalc.shtml#igrfwmm)
  cal.mag_field = 45.00; // approximate value for locations along the equator

  // in Radians/s
  cal.gyro_zerorate[0] = 0.05;
  cal.gyro_zerorate[1] = -0.01;
  cal.gyro_zerorate[2] = -0.01;

  if (! cal.saveCalibration()) {
    Serial.println("**WARNING** Couldn't save calibration");
  } else {
    Serial.println("Wrote calibration");    
  }

  cal.printSavedCalibration();

  /* battery_publisher init*/
  rclc_publisher_init_default(
    &battery_publisher,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Float32),
    "battery_voltage");
  rclc_timer_init_default(
    &timer2,
    &support,
    RCL_MS_TO_NS(200),
    timer2_callback);
  rclc_executor_add_timer(&executor, &timer2);
  pinMode(5, INPUT);

  /* sbscriber init */
  rclc_subscription_init_default(
    &led_ctrl_subcriber,
    &node,
    ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
    "led_control");
  //add the subscriber of the executor
  rclc_executor_add_subscription(&executor, &led_ctrl_subcriber, &sub_msg, &callback_led_ctrl_subscription, ON_NEW_DATA);
  //inital the LED
  pinMode(2, OUTPUT);

  /* service init */
  rclc_service_init_default(&add_service, &node, ROSIDL_GET_SRV_TYPE_SUPPORT(example_interfaces, srv, AddTwoInts), "/addtwoints");
  rclc_executor_add_service(&executor, &add_service, &req, &res, add_service_callback);

  /**
   * @brief 创建一个任务在Core 0 上
   * microros_task    任务函数
   * "microros_task"  任务名称
   * 10240      任务占用内存大小
   * NULL         任务参数，为空
   * 1               任务优先级
   * NULL     任务Handle可以为空
   * 0                 内核编号
   */
  xTaskCreatePinnedToCore(microros_task, "microros_task", 10240, NULL, 1, NULL, 0); //before the rclc_executor_init function excute


  /* 舵机 */
  Serial.println("begin the servo");
  pinMode(Trig, OUTPUT);     // 初始化舵机和超声波
  pinMode(Echo, INPUT);      // 要检测引脚上输入的脉冲宽度，需要先设置为输入状态
  servo1.setPeriodHertz(50); // Standard 50hz servo
  servo1.attach(4, 500, 2500);
  servo1.write(90.0);
  Serial.println("the servo end");
  #endif

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
    return;
  }
  sprintf(time_str, "%04d-%02d-%02d %02d:%02d:%02d ", year(), month(), day(), hour(), minute(), second());
  Serial.println(time_str);

}

void loop()
{
  /******this is for adc voltage collection */
  // #if 1
  // delay(50);
  // 循环处理数据
  rclc_executor_spin_some(&executor, RCL_MS_TO_NS(1));
  /* multi core run*/
  // Serial.printf("do some control on core:%d\n", xPortGetCoreID());

}