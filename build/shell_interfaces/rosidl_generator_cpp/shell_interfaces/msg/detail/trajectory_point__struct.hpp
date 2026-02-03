// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from shell_interfaces:msg/TrajectoryPoint.idl
// generated code does not contain a copyright notice

#ifndef SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY_POINT__STRUCT_HPP_
#define SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY_POINT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__shell_interfaces__msg__TrajectoryPoint __attribute__((deprecated))
#else
# define DEPRECATED__shell_interfaces__msg__TrajectoryPoint __declspec(deprecated)
#endif

namespace shell_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TrajectoryPoint_
{
  using Type = TrajectoryPoint_<ContainerAllocator>;

  explicit TrajectoryPoint_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->theta = 0.0;
      this->v = 0.0;
    }
  }

  explicit TrajectoryPoint_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->x = 0.0;
      this->y = 0.0;
      this->theta = 0.0;
      this->v = 0.0;
    }
  }

  // field types and members
  using _x_type =
    double;
  _x_type x;
  using _y_type =
    double;
  _y_type y;
  using _theta_type =
    double;
  _theta_type theta;
  using _v_type =
    double;
  _v_type v;

  // setters for named parameter idiom
  Type & set__x(
    const double & _arg)
  {
    this->x = _arg;
    return *this;
  }
  Type & set__y(
    const double & _arg)
  {
    this->y = _arg;
    return *this;
  }
  Type & set__theta(
    const double & _arg)
  {
    this->theta = _arg;
    return *this;
  }
  Type & set__v(
    const double & _arg)
  {
    this->v = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    shell_interfaces::msg::TrajectoryPoint_<ContainerAllocator> *;
  using ConstRawPtr =
    const shell_interfaces::msg::TrajectoryPoint_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<shell_interfaces::msg::TrajectoryPoint_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<shell_interfaces::msg::TrajectoryPoint_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      shell_interfaces::msg::TrajectoryPoint_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<shell_interfaces::msg::TrajectoryPoint_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      shell_interfaces::msg::TrajectoryPoint_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<shell_interfaces::msg::TrajectoryPoint_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<shell_interfaces::msg::TrajectoryPoint_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<shell_interfaces::msg::TrajectoryPoint_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__shell_interfaces__msg__TrajectoryPoint
    std::shared_ptr<shell_interfaces::msg::TrajectoryPoint_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__shell_interfaces__msg__TrajectoryPoint
    std::shared_ptr<shell_interfaces::msg::TrajectoryPoint_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TrajectoryPoint_ & other) const
  {
    if (this->x != other.x) {
      return false;
    }
    if (this->y != other.y) {
      return false;
    }
    if (this->theta != other.theta) {
      return false;
    }
    if (this->v != other.v) {
      return false;
    }
    return true;
  }
  bool operator!=(const TrajectoryPoint_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TrajectoryPoint_

// alias to use template instance with default allocator
using TrajectoryPoint =
  shell_interfaces::msg::TrajectoryPoint_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace shell_interfaces

#endif  // SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY_POINT__STRUCT_HPP_
