// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from multi_sensor_interfaces:srv/Multisensor.idl
// generated code does not contain a copyright notice

#ifndef MULTI_SENSOR_INTERFACES__SRV__DETAIL__MULTISENSOR__TRAITS_HPP_
#define MULTI_SENSOR_INTERFACES__SRV__DETAIL__MULTISENSOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "multi_sensor_interfaces/srv/detail/multisensor__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace multi_sensor_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Multisensor_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: mid_finger
  {
    out << "mid_finger: ";
    rosidl_generator_traits::value_to_yaml(msg.mid_finger, out);
    out << ", ";
  }

  // member: index_finger
  {
    out << "index_finger: ";
    rosidl_generator_traits::value_to_yaml(msg.index_finger, out);
    out << ", ";
  }

  // member: ring_finger
  {
    out << "ring_finger: ";
    rosidl_generator_traits::value_to_yaml(msg.ring_finger, out);
    out << ", ";
  }

  // member: location
  {
    out << "location: ";
    rosidl_generator_traits::value_to_yaml(msg.location, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Multisensor_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mid_finger
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mid_finger: ";
    rosidl_generator_traits::value_to_yaml(msg.mid_finger, out);
    out << "\n";
  }

  // member: index_finger
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "index_finger: ";
    rosidl_generator_traits::value_to_yaml(msg.index_finger, out);
    out << "\n";
  }

  // member: ring_finger
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ring_finger: ";
    rosidl_generator_traits::value_to_yaml(msg.ring_finger, out);
    out << "\n";
  }

  // member: location
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "location: ";
    rosidl_generator_traits::value_to_yaml(msg.location, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Multisensor_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace multi_sensor_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use multi_sensor_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const multi_sensor_interfaces::srv::Multisensor_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  multi_sensor_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use multi_sensor_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const multi_sensor_interfaces::srv::Multisensor_Request & msg)
{
  return multi_sensor_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<multi_sensor_interfaces::srv::Multisensor_Request>()
{
  return "multi_sensor_interfaces::srv::Multisensor_Request";
}

template<>
inline const char * name<multi_sensor_interfaces::srv::Multisensor_Request>()
{
  return "multi_sensor_interfaces/srv/Multisensor_Request";
}

template<>
struct has_fixed_size<multi_sensor_interfaces::srv::Multisensor_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<multi_sensor_interfaces::srv::Multisensor_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<multi_sensor_interfaces::srv::Multisensor_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace multi_sensor_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const Multisensor_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: result
  {
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Multisensor_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result: ";
    rosidl_generator_traits::value_to_yaml(msg.result, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Multisensor_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace multi_sensor_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use multi_sensor_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const multi_sensor_interfaces::srv::Multisensor_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  multi_sensor_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use multi_sensor_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const multi_sensor_interfaces::srv::Multisensor_Response & msg)
{
  return multi_sensor_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<multi_sensor_interfaces::srv::Multisensor_Response>()
{
  return "multi_sensor_interfaces::srv::Multisensor_Response";
}

template<>
inline const char * name<multi_sensor_interfaces::srv::Multisensor_Response>()
{
  return "multi_sensor_interfaces/srv/Multisensor_Response";
}

template<>
struct has_fixed_size<multi_sensor_interfaces::srv::Multisensor_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<multi_sensor_interfaces::srv::Multisensor_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<multi_sensor_interfaces::srv::Multisensor_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<multi_sensor_interfaces::srv::Multisensor>()
{
  return "multi_sensor_interfaces::srv::Multisensor";
}

template<>
inline const char * name<multi_sensor_interfaces::srv::Multisensor>()
{
  return "multi_sensor_interfaces/srv/Multisensor";
}

template<>
struct has_fixed_size<multi_sensor_interfaces::srv::Multisensor>
  : std::integral_constant<
    bool,
    has_fixed_size<multi_sensor_interfaces::srv::Multisensor_Request>::value &&
    has_fixed_size<multi_sensor_interfaces::srv::Multisensor_Response>::value
  >
{
};

template<>
struct has_bounded_size<multi_sensor_interfaces::srv::Multisensor>
  : std::integral_constant<
    bool,
    has_bounded_size<multi_sensor_interfaces::srv::Multisensor_Request>::value &&
    has_bounded_size<multi_sensor_interfaces::srv::Multisensor_Response>::value
  >
{
};

template<>
struct is_service<multi_sensor_interfaces::srv::Multisensor>
  : std::true_type
{
};

template<>
struct is_service_request<multi_sensor_interfaces::srv::Multisensor_Request>
  : std::true_type
{
};

template<>
struct is_service_response<multi_sensor_interfaces::srv::Multisensor_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // MULTI_SENSOR_INTERFACES__SRV__DETAIL__MULTISENSOR__TRAITS_HPP_
