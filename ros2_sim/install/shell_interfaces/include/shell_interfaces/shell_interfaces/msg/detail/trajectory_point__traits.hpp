// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from shell_interfaces:msg/TrajectoryPoint.idl
// generated code does not contain a copyright notice

#ifndef SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY_POINT__TRAITS_HPP_
#define SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY_POINT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "shell_interfaces/msg/detail/trajectory_point__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace shell_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const TrajectoryPoint & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: theta
  {
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << ", ";
  }

  // member: v
  {
    out << "v: ";
    rosidl_generator_traits::value_to_yaml(msg.v, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const TrajectoryPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << "\n";
  }

  // member: v
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v: ";
    rosidl_generator_traits::value_to_yaml(msg.v, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const TrajectoryPoint & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace shell_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use shell_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const shell_interfaces::msg::TrajectoryPoint & msg,
  std::ostream & out, size_t indentation = 0)
{
  shell_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use shell_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const shell_interfaces::msg::TrajectoryPoint & msg)
{
  return shell_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<shell_interfaces::msg::TrajectoryPoint>()
{
  return "shell_interfaces::msg::TrajectoryPoint";
}

template<>
inline const char * name<shell_interfaces::msg::TrajectoryPoint>()
{
  return "shell_interfaces/msg/TrajectoryPoint";
}

template<>
struct has_fixed_size<shell_interfaces::msg::TrajectoryPoint>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<shell_interfaces::msg::TrajectoryPoint>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<shell_interfaces::msg::TrajectoryPoint>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY_POINT__TRAITS_HPP_
