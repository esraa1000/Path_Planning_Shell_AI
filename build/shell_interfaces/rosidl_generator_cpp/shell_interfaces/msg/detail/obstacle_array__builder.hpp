// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from shell_interfaces:msg/ObstacleArray.idl
// generated code does not contain a copyright notice

#ifndef SHELL_INTERFACES__MSG__DETAIL__OBSTACLE_ARRAY__BUILDER_HPP_
#define SHELL_INTERFACES__MSG__DETAIL__OBSTACLE_ARRAY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "shell_interfaces/msg/detail/obstacle_array__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace shell_interfaces
{

namespace msg
{

namespace builder
{

class Init_ObstacleArray_obstacles
{
public:
  explicit Init_ObstacleArray_obstacles(::shell_interfaces::msg::ObstacleArray & msg)
  : msg_(msg)
  {}
  ::shell_interfaces::msg::ObstacleArray obstacles(::shell_interfaces::msg::ObstacleArray::_obstacles_type arg)
  {
    msg_.obstacles = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shell_interfaces::msg::ObstacleArray msg_;
};

class Init_ObstacleArray_header
{
public:
  Init_ObstacleArray_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ObstacleArray_obstacles header(::shell_interfaces::msg::ObstacleArray::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ObstacleArray_obstacles(msg_);
  }

private:
  ::shell_interfaces::msg::ObstacleArray msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::shell_interfaces::msg::ObstacleArray>()
{
  return shell_interfaces::msg::builder::Init_ObstacleArray_header();
}

}  // namespace shell_interfaces

#endif  // SHELL_INTERFACES__MSG__DETAIL__OBSTACLE_ARRAY__BUILDER_HPP_
