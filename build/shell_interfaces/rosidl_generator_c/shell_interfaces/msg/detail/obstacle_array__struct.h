// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from shell_interfaces:msg/ObstacleArray.idl
// generated code does not contain a copyright notice

#ifndef SHELL_INTERFACES__MSG__DETAIL__OBSTACLE_ARRAY__STRUCT_H_
#define SHELL_INTERFACES__MSG__DETAIL__OBSTACLE_ARRAY__STRUCT_H_

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
// Member 'obstacles'
#include "shell_interfaces/msg/detail/obstacle__struct.h"

/// Struct defined in msg/ObstacleArray in the package shell_interfaces.
typedef struct shell_interfaces__msg__ObstacleArray
{
  std_msgs__msg__Header header;
  shell_interfaces__msg__Obstacle__Sequence obstacles;
} shell_interfaces__msg__ObstacleArray;

// Struct for a sequence of shell_interfaces__msg__ObstacleArray.
typedef struct shell_interfaces__msg__ObstacleArray__Sequence
{
  shell_interfaces__msg__ObstacleArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} shell_interfaces__msg__ObstacleArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SHELL_INTERFACES__MSG__DETAIL__OBSTACLE_ARRAY__STRUCT_H_
