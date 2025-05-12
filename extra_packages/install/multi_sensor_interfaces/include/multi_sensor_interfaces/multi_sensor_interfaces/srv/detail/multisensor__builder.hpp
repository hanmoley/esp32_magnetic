// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from multi_sensor_interfaces:srv/Multisensor.idl
// generated code does not contain a copyright notice

#ifndef MULTI_SENSOR_INTERFACES__SRV__DETAIL__MULTISENSOR__BUILDER_HPP_
#define MULTI_SENSOR_INTERFACES__SRV__DETAIL__MULTISENSOR__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "multi_sensor_interfaces/srv/detail/multisensor__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace multi_sensor_interfaces
{

namespace srv
{

namespace builder
{

class Init_Multisensor_Request_location
{
public:
  explicit Init_Multisensor_Request_location(::multi_sensor_interfaces::srv::Multisensor_Request & msg)
  : msg_(msg)
  {}
  ::multi_sensor_interfaces::srv::Multisensor_Request location(::multi_sensor_interfaces::srv::Multisensor_Request::_location_type arg)
  {
    msg_.location = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_sensor_interfaces::srv::Multisensor_Request msg_;
};

class Init_Multisensor_Request_ring_finger
{
public:
  explicit Init_Multisensor_Request_ring_finger(::multi_sensor_interfaces::srv::Multisensor_Request & msg)
  : msg_(msg)
  {}
  Init_Multisensor_Request_location ring_finger(::multi_sensor_interfaces::srv::Multisensor_Request::_ring_finger_type arg)
  {
    msg_.ring_finger = std::move(arg);
    return Init_Multisensor_Request_location(msg_);
  }

private:
  ::multi_sensor_interfaces::srv::Multisensor_Request msg_;
};

class Init_Multisensor_Request_index_finger
{
public:
  explicit Init_Multisensor_Request_index_finger(::multi_sensor_interfaces::srv::Multisensor_Request & msg)
  : msg_(msg)
  {}
  Init_Multisensor_Request_ring_finger index_finger(::multi_sensor_interfaces::srv::Multisensor_Request::_index_finger_type arg)
  {
    msg_.index_finger = std::move(arg);
    return Init_Multisensor_Request_ring_finger(msg_);
  }

private:
  ::multi_sensor_interfaces::srv::Multisensor_Request msg_;
};

class Init_Multisensor_Request_mid_finger
{
public:
  Init_Multisensor_Request_mid_finger()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Multisensor_Request_index_finger mid_finger(::multi_sensor_interfaces::srv::Multisensor_Request::_mid_finger_type arg)
  {
    msg_.mid_finger = std::move(arg);
    return Init_Multisensor_Request_index_finger(msg_);
  }

private:
  ::multi_sensor_interfaces::srv::Multisensor_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_sensor_interfaces::srv::Multisensor_Request>()
{
  return multi_sensor_interfaces::srv::builder::Init_Multisensor_Request_mid_finger();
}

}  // namespace multi_sensor_interfaces


namespace multi_sensor_interfaces
{

namespace srv
{

namespace builder
{

class Init_Multisensor_Response_result
{
public:
  Init_Multisensor_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::multi_sensor_interfaces::srv::Multisensor_Response result(::multi_sensor_interfaces::srv::Multisensor_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::multi_sensor_interfaces::srv::Multisensor_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::multi_sensor_interfaces::srv::Multisensor_Response>()
{
  return multi_sensor_interfaces::srv::builder::Init_Multisensor_Response_result();
}

}  // namespace multi_sensor_interfaces

#endif  // MULTI_SENSOR_INTERFACES__SRV__DETAIL__MULTISENSOR__BUILDER_HPP_
