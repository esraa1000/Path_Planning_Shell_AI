// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from shell_interfaces:msg/Boundary.idl
// generated code does not contain a copyright notice

#ifndef SHELL_INTERFACES__MSG__DETAIL__BOUNDARY__STRUCT_HPP_
#define SHELL_INTERFACES__MSG__DETAIL__BOUNDARY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'points'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__shell_interfaces__msg__Boundary __attribute__((deprecated))
#else
# define DEPRECATED__shell_interfaces__msg__Boundary __declspec(deprecated)
#endif

namespace shell_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Boundary_
{
  using Type = Boundary_<ContainerAllocator>;

  explicit Boundary_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    (void)_init;
  }

  explicit Boundary_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _points_type =
    std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>>;
  _points_type points;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__points(
    const std::vector<geometry_msgs::msg::Point_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<geometry_msgs::msg::Point_<ContainerAllocator>>> & _arg)
  {
    this->points = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    shell_interfaces::msg::Boundary_<ContainerAllocator> *;
  using ConstRawPtr =
    const shell_interfaces::msg::Boundary_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<shell_interfaces::msg::Boundary_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<shell_interfaces::msg::Boundary_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      shell_interfaces::msg::Boundary_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<shell_interfaces::msg::Boundary_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      shell_interfaces::msg::Boundary_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<shell_interfaces::msg::Boundary_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<shell_interfaces::msg::Boundary_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<shell_interfaces::msg::Boundary_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__shell_interfaces__msg__Boundary
    std::shared_ptr<shell_interfaces::msg::Boundary_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__shell_interfaces__msg__Boundary
    std::shared_ptr<shell_interfaces::msg::Boundary_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Boundary_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->points != other.points) {
      return false;
    }
    return true;
  }
  bool operator!=(const Boundary_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Boundary_

// alias to use template instance with default allocator
using Boundary =
  shell_interfaces::msg::Boundary_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace shell_interfaces

#endif  // SHELL_INTERFACES__MSG__DETAIL__BOUNDARY__STRUCT_HPP_
