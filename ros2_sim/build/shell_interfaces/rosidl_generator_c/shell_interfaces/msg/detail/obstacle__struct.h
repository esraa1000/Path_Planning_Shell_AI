// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from shell_interfaces:msg/Obstacle.idl
// generated code does not contain a copyright notice

#ifndef SHELL_INTERFACES__MSG__DETAIL__OBSTACLE__STRUCT_H_
#define SHELL_INTERFACES__MSG__DETAIL__OBSTACLE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'center'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/Obstacle in the package shell_interfaces.
typedef struct shell_interfaces__msg__Obstacle
{
  geometry_msgs__msg__Point center;
  double radius;
} shell_interfaces__msg__Obstacle;

// Struct for a sequence of shell_interfaces__msg__Obstacle.
typedef struct shell_interfaces__msg__Obstacle__Sequence
{
  shell_interfaces__msg__Obstacle * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shell_interfaces__msg__Obstacle__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SHELL_INTERFACES__MSG__DETAIL__OBSTACLE__STRUCT_H_
