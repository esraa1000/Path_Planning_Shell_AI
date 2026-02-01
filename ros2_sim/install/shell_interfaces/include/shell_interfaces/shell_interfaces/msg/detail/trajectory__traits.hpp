// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from shell_interfaces:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY__TRAITS_HPP_
#define SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "shell_interfaces/msg/detail/trajectory__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'points'
#include "shell_interfaces/msg/detail/trajectory_point__traits.hpp"

namespace shell_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Trajectory & msg,
  std::ostream & out)
{
  out << "{";
  // member: points
  {
    if (msg.points.size() == 0) {
      out << "points: []";
    } else {
      out << "points: [";
      size_t pending_items = msg.points.size();
      for (auto item : msg.points) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Trajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: points
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.points.size() == 0) {
      out << "points: []\n";
    } else {
      out << "points:\n";
      for (auto item : msg.points) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Trajectory & msg, bool use_flow_style = false)
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
  const shell_interfaces::msg::Trajectory & msg,
  std::ostream & out, size_t indentation = 0)
{
  shell_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use shell_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const shell_interfaces::msg::Trajectory & msg)
{
  return shell_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<shell_interfaces::msg::Trajectory>()
{
  return "shell_interfaces::msg::Trajectory";
}

template<>
inline const char * name<shell_interfaces::msg::Trajectory>()
{
  return "shell_interfaces/msg/Trajectory";
}

template<>
struct has_fixed_size<shell_interfaces::msg::Trajectory>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<shell_interfaces::msg::Trajectory>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<shell_interfaces::msg::Trajectory>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY__TRAITS_HPP_
