// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from shell_interfaces:msg/Obstacle.idl
// generated code does not contain a copyright notice

#ifndef SHELL_INTERFACES__MSG__DETAIL__OBSTACLE__BUILDER_HPP_
#define SHELL_INTERFACES__MSG__DETAIL__OBSTACLE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "shell_interfaces/msg/detail/obstacle__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace shell_interfaces
{

namespace msg
{

namespace builder
{

class Init_Obstacle_radius
{
public:
  explicit Init_Obstacle_radius(::shell_interfaces::msg::Obstacle & msg)
  : msg_(msg)
  {}
  ::shell_interfaces::msg::Obstacle radius(::shell_interfaces::msg::Obstacle::_radius_type arg)
  {
    msg_.radius = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shell_interfaces::msg::Obstacle msg_;
};

class Init_Obstacle_center
{
public:
  Init_Obstacle_center()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Obstacle_radius center(::shell_interfaces::msg::Obstacle::_center_type arg)
  {
    msg_.center = std::move(arg);
    return Init_Obstacle_radius(msg_);
  }

private:
  ::shell_interfaces::msg::Obstacle msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::shell_interfaces::msg::Obstacle>()
{
  return shell_interfaces::msg::builder::Init_Obstacle_center();
}

}  // namespace shell_interfaces

#endif  // SHELL_INTERFACES__MSG__DETAIL__OBSTACLE__BUILDER_HPP_
