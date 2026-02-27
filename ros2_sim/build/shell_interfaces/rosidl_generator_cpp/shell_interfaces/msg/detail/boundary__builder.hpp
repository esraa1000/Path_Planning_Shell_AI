// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from shell_interfaces:msg/Boundary.idl
// generated code does not contain a copyright notice

#ifndef SHELL_INTERFACES__MSG__DETAIL__BOUNDARY__BUILDER_HPP_
#define SHELL_INTERFACES__MSG__DETAIL__BOUNDARY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "shell_interfaces/msg/detail/boundary__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace shell_interfaces
{

namespace msg
{

namespace builder
{

class Init_Boundary_points
{
public:
  explicit Init_Boundary_points(::shell_interfaces::msg::Boundary & msg)
  : msg_(msg)
  {}
  ::shell_interfaces::msg::Boundary points(::shell_interfaces::msg::Boundary::_points_type arg)
  {
    msg_.points = std::move(arg);
    return std::move(msg_);
  }

private:
  ::shell_interfaces::msg::Boundary msg_;
};

class Init_Boundary_header
{
public:
  Init_Boundary_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Boundary_points header(::shell_interfaces::msg::Boundary::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Boundary_points(msg_);
  }

private:
  ::shell_interfaces::msg::Boundary msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::shell_interfaces::msg::Boundary>()
{
  return shell_interfaces::msg::builder::Init_Boundary_header();
}

}  // namespace shell_interfaces

#endif  // SHELL_INTERFACES__MSG__DETAIL__BOUNDARY__BUILDER_HPP_
