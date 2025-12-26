// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from shell_interfaces:msg/TrajectoryPoint.idl
// generated code does not contain a copyright notice

#ifndef SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY_POINT__STRUCT_H_
#define SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY_POINT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/TrajectoryPoint in the package shell_interfaces.
typedef struct shell_interfaces__msg__TrajectoryPoint
{
  double x;
  double y;
  double theta;
  double v;
} shell_interfaces__msg__TrajectoryPoint;

// Struct for a sequence of shell_interfaces__msg__TrajectoryPoint.
typedef struct shell_interfaces__msg__TrajectoryPoint__Sequence
{
  shell_interfaces__msg__TrajectoryPoint * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shell_interfaces__msg__TrajectoryPoint__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SHELL_INTERFACES__MSG__DETAIL__TRAJECTORY_POINT__STRUCT_H_
