// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from shell_interfaces:msg/Boundary.idl
// generated code does not contain a copyright notice

#ifndef SHELL_INTERFACES__MSG__DETAIL__BOUNDARY__STRUCT_H_
#define SHELL_INTERFACES__MSG__DETAIL__BOUNDARY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'points'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Boundary in the package shell_interfaces.
typedef struct shell_interfaces__msg__Boundary
{
  std_msgs__msg__Header header;
  geometry_msgs__msg__Point__Sequence points;
} shell_interfaces__msg__Boundary;

// Struct for a sequence of shell_interfaces__msg__Boundary.
typedef struct shell_interfaces__msg__Boundary__Sequence
{
  shell_interfaces__msg__Boundary * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shell_interfaces__msg__Boundary__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SHELL_INTERFACES__MSG__DETAIL__BOUNDARY__STRUCT_H_
