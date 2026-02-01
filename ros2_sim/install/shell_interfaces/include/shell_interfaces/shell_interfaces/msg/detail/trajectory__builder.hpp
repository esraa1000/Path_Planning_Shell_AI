// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from shell_interfaces:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
#define SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "shell_interfaces/msg/detail/trajectory__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace shell_interfaces
{

namespace msg
{

namespace builder
{

class Init_Trajectory_points
{
public:
  Init_Trajectory_points()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::shell_interfaces::msg::Trajectory points(::shell_interfaces::msg::Trajectory::_points_type arg)
  {
    msg_.points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shell_interfaces::msg::Trajectory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::shell_interfaces::msg::Trajectory>()
{
  return shell_interfaces::msg::builder::Init_Trajectory_points();
}

}  // namespace shell_interfaces

#endif  // SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
