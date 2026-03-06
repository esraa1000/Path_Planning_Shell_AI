// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from shell_interfaces:msg/Obstacle.idl
// generated code does not contain a copyright notice

#ifndef SHELL_INTERFACES__MSG__DETAIL__OBSTACLE__TRAITS_HPP_
#define SHELL_INTERFACES__MSG__DETAIL__OBSTACLE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "shell_interfaces/msg/detail/obstacle__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'center'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace shell_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Obstacle & msg,
  std::ostream & out)
{
  out << "{";
  // member: center
  {
    out << "center: ";
    to_flow_style_yaml(msg.center, out);
    out << ", ";
  }

  // member: radius
  {
    out << "radius: ";
    rosidl_generator_traits::value_to_yaml(msg.radius, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Obstacle & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: center
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "center:\n";
    to_block_style_yaml(msg.center, out, indentation + 2);
  }

  // member: radius
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "radius: ";
    rosidl_generator_traits::value_to_yaml(msg.radius, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Obstacle & msg, bool use_flow_style = false)
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
  const shell_interfaces::msg::Obstacle & msg,
  std::ostream & out, size_t indentation = 0)
{
  shell_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use shell_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const shell_interfaces::msg::Obstacle & msg)
{
  return shell_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<shell_interfaces::msg::Obstacle>()
{
  return "shell_interfaces::msg::Obstacle";
}

template<>
inline const char * name<shell_interfaces::msg::Obstacle>()
{
  return "shell_interfaces/msg/Obstacle";
}

template<>
struct has_fixed_size<shell_interfaces::msg::Obstacle>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value> {};

template<>
struct has_bounded_size<shell_interfaces::msg::Obstacle>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value> {};

template<>
struct is_message<shell_interfaces::msg::Obstacle>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SHELL_INTERFACES__MSG__DETAIL__OBSTACLE__TRAITS_HPP_
