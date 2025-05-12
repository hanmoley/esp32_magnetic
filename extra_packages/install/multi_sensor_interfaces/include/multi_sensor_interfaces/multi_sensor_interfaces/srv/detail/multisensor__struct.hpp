// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from multi_sensor_interfaces:srv/Multisensor.idl
// generated code does not contain a copyright notice

#ifndef MULTI_SENSOR_INTERFACES__SRV__DETAIL__MULTISENSOR__STRUCT_HPP_
#define MULTI_SENSOR_INTERFACES__SRV__DETAIL__MULTISENSOR__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__multi_sensor_interfaces__srv__Multisensor_Request __attribute__((deprecated))
#else
# define DEPRECATED__multi_sensor_interfaces__srv__Multisensor_Request __declspec(deprecated)
#endif

namespace multi_sensor_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Multisensor_Request_
{
  using Type = Multisensor_Request_<ContainerAllocator>;

  explicit Multisensor_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mid_finger = 0.0f;
      this->index_finger = 0.0f;
      this->ring_finger = 0.0f;
      this->location = "";
    }
  }

  explicit Multisensor_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : location(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mid_finger = 0.0f;
      this->index_finger = 0.0f;
      this->ring_finger = 0.0f;
      this->location = "";
    }
  }

  // field types and members
  using _mid_finger_type =
    float;
  _mid_finger_type mid_finger;
  using _index_finger_type =
    float;
  _index_finger_type index_finger;
  using _ring_finger_type =
    float;
  _ring_finger_type ring_finger;
  using _location_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _location_type location;

  // setters for named parameter idiom
  Type & set__mid_finger(
    const float & _arg)
  {
    this->mid_finger = _arg;
    return *this;
  }
  Type & set__index_finger(
    const float & _arg)
  {
    this->index_finger = _arg;
    return *this;
  }
  Type & set__ring_finger(
    const float & _arg)
  {
    this->ring_finger = _arg;
    return *this;
  }
  Type & set__location(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->location = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    multi_sensor_interfaces::srv::Multisensor_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const multi_sensor_interfaces::srv::Multisensor_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<multi_sensor_interfaces::srv::Multisensor_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<multi_sensor_interfaces::srv::Multisensor_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      multi_sensor_interfaces::srv::Multisensor_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<multi_sensor_interfaces::srv::Multisensor_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      multi_sensor_interfaces::srv::Multisensor_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<multi_sensor_interfaces::srv::Multisensor_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<multi_sensor_interfaces::srv::Multisensor_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<multi_sensor_interfaces::srv::Multisensor_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__multi_sensor_interfaces__srv__Multisensor_Request
    std::shared_ptr<multi_sensor_interfaces::srv::Multisensor_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__multi_sensor_interfaces__srv__Multisensor_Request
    std::shared_ptr<multi_sensor_interfaces::srv::Multisensor_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Multisensor_Request_ & other) const
  {
    if (this->mid_finger != other.mid_finger) {
      return false;
    }
    if (this->index_finger != other.index_finger) {
      return false;
    }
    if (this->ring_finger != other.ring_finger) {
      return false;
    }
    if (this->location != other.location) {
      return false;
    }
    return true;
  }
  bool operator!=(const Multisensor_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Multisensor_Request_

// alias to use template instance with default allocator
using Multisensor_Request =
  multi_sensor_interfaces::srv::Multisensor_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace multi_sensor_interfaces


#ifndef _WIN32
# define DEPRECATED__multi_sensor_interfaces__srv__Multisensor_Response __attribute__((deprecated))
#else
# define DEPRECATED__multi_sensor_interfaces__srv__Multisensor_Response __declspec(deprecated)
#endif

namespace multi_sensor_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Multisensor_Response_
{
  using Type = Multisensor_Response_<ContainerAllocator>;

  explicit Multisensor_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = 0l;
    }
  }

  explicit Multisensor_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = 0l;
    }
  }

  // field types and members
  using _result_type =
    int32_t;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const int32_t & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    multi_sensor_interfaces::srv::Multisensor_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const multi_sensor_interfaces::srv::Multisensor_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<multi_sensor_interfaces::srv::Multisensor_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<multi_sensor_interfaces::srv::Multisensor_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      multi_sensor_interfaces::srv::Multisensor_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<multi_sensor_interfaces::srv::Multisensor_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      multi_sensor_interfaces::srv::Multisensor_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<multi_sensor_interfaces::srv::Multisensor_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<multi_sensor_interfaces::srv::Multisensor_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<multi_sensor_interfaces::srv::Multisensor_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__multi_sensor_interfaces__srv__Multisensor_Response
    std::shared_ptr<multi_sensor_interfaces::srv::Multisensor_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__multi_sensor_interfaces__srv__Multisensor_Response
    std::shared_ptr<multi_sensor_interfaces::srv::Multisensor_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Multisensor_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const Multisensor_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Multisensor_Response_

// alias to use template instance with default allocator
using Multisensor_Response =
  multi_sensor_interfaces::srv::Multisensor_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace multi_sensor_interfaces

namespace multi_sensor_interfaces
{

namespace srv
{

struct Multisensor
{
  using Request = multi_sensor_interfaces::srv::Multisensor_Request;
  using Response = multi_sensor_interfaces::srv::Multisensor_Response;
};

}  // namespace srv

}  // namespace multi_sensor_interfaces

#endif  // MULTI_SENSOR_INTERFACES__SRV__DETAIL__MULTISENSOR__STRUCT_HPP_
