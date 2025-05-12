// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from multi_sensor_interfaces:srv/Multisensor.idl
// generated code does not contain a copyright notice

#ifndef MULTI_SENSOR_INTERFACES__SRV__DETAIL__MULTISENSOR__STRUCT_H_
#define MULTI_SENSOR_INTERFACES__SRV__DETAIL__MULTISENSOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'location'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Multisensor in the package multi_sensor_interfaces.
typedef struct multi_sensor_interfaces__srv__Multisensor_Request
{
  float mid_finger;
  float index_finger;
  float ring_finger;
  rosidl_runtime_c__String location;
} multi_sensor_interfaces__srv__Multisensor_Request;

// Struct for a sequence of multi_sensor_interfaces__srv__Multisensor_Request.
typedef struct multi_sensor_interfaces__srv__Multisensor_Request__Sequence
{
  multi_sensor_interfaces__srv__Multisensor_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_sensor_interfaces__srv__Multisensor_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Multisensor in the package multi_sensor_interfaces.
typedef struct multi_sensor_interfaces__srv__Multisensor_Response
{
  int32_t result;
} multi_sensor_interfaces__srv__Multisensor_Response;

// Struct for a sequence of multi_sensor_interfaces__srv__Multisensor_Response.
typedef struct multi_sensor_interfaces__srv__Multisensor_Response__Sequence
{
  multi_sensor_interfaces__srv__Multisensor_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} multi_sensor_interfaces__srv__Multisensor_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MULTI_SENSOR_INTERFACES__SRV__DETAIL__MULTISENSOR__STRUCT_H_
