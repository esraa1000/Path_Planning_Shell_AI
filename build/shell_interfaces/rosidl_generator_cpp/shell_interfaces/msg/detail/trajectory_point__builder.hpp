// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from shell_interfaces:msg/TrajectoryPoint.idl
// generated code does not contain a copyright notice

#ifndef SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY_POINT__BUILDER_HPP_
#define SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY_POINT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "shell_interfaces/msg/detail/trajectory_point__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace shell_interfaces
{

namespace msg
{

namespace builder
{

class Init_TrajectoryPoint_v
{
public:
  explicit Init_TrajectoryPoint_v(::shell_interfaces::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  ::shell_interfaces::msg::TrajectoryPoint v(::shell_interfaces::msg::TrajectoryPoint::_v_type arg)
  {
    msg_.v = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shell_interfaces::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_theta
{
public:
  explicit Init_TrajectoryPoint_theta(::shell_interfaces::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_v theta(::shell_interfaces::msg::TrajectoryPoint::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return Init_TrajectoryPoint_v(msg_);
  }

private:
  ::shell_interfaces::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_y
{
public:
  explicit Init_TrajectoryPoint_y(::shell_interfaces::msg::TrajectoryPoint & msg)
  : msg_(msg)
  {}
  Init_TrajectoryPoint_theta y(::shell_interfaces::msg::TrajectoryPoint::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_TrajectoryPoint_theta(msg_);
  }

private:
  ::shell_interfaces::msg::TrajectoryPoint msg_;
};

class Init_TrajectoryPoint_x
{
public:
  Init_TrajectoryPoint_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TrajectoryPoint_y x(::shell_interfaces::msg::TrajectoryPoint::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_TrajectoryPoint_y(msg_);
  }

private:
  ::shell_interfaces::msg::TrajectoryPoint msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::shell_interfaces::msg::TrajectoryPoint>()
{
  return shell_interfaces::msg::builder::Init_TrajectoryPoint_x();
}

}  // namespace shell_interfaces

#endif  // SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY_POINT__BUILDER_HPP_
