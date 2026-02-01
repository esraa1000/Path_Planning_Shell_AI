// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from shell_interfaces:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY__STRUCT_H_
#define SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'points'
#include "shell_interfaces/msg/detail/trajectory_point__struct.h"

/// Struct defined in msg/Trajectory in the package shell_interfaces.
typedef struct shell_interfaces__msg__Trajectory
{
  shell_interfaces__msg__TrajectoryPoint__Sequence points;
} shell_interfaces__msg__Trajectory;

// Struct for a sequence of shell_interfaces__msg__Trajectory.
typedef struct shell_interfaces__msg__Trajectory__Sequence
{
  shell_interfaces__msg__Trajectory * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shell_interfaces__msg__Trajectory__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY__STRUCT_H_
