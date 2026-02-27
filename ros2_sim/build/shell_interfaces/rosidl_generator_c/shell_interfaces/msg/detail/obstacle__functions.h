// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from shell_interfaces:msg/Obstacle.idl
// generated code does not contain a copyright notice

#ifndef SHELL_INTERFACES__MSG__DETAIL__OBSTACLE__FUNCTIONS_H_
#define SHELL_INTERFACES__MSG__DETAIL__OBSTACLE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "shell_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "shell_interfaces/msg/detail/obstacle__struct.h"

/// Initialize msg/Obstacle message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * shell_interfaces__msg__Obstacle
 * )) before or use
 * shell_interfaces__msg__Obstacle__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
bool
shell_interfaces__msg__Obstacle__init(shell_interfaces__msg__Obstacle * msg);

/// Finalize msg/Obstacle message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
void
shell_interfaces__msg__Obstacle__fini(shell_interfaces__msg__Obstacle * msg);

/// Create msg/Obstacle message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * shell_interfaces__msg__Obstacle__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
shell_interfaces__msg__Obstacle *
shell_interfaces__msg__Obstacle__create();

/// Destroy msg/Obstacle message.
/**
 * It calls
 * shell_interfaces__msg__Obstacle__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
void
shell_interfaces__msg__Obstacle__destroy(shell_interfaces__msg__Obstacle * msg);

/// Check for msg/Obstacle message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
bool
shell_interfaces__msg__Obstacle__are_equal(const shell_interfaces__msg__Obstacle * lhs, const shell_interfaces__msg__Obstacle * rhs);

/// Copy a msg/Obstacle message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
bool
shell_interfaces__msg__Obstacle__copy(
  const shell_interfaces__msg__Obstacle * input,
  shell_interfaces__msg__Obstacle * output);

/// Initialize array of msg/Obstacle messages.
/**
 * It allocates the memory for the number of elements and calls
 * shell_interfaces__msg__Obstacle__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
bool
shell_interfaces__msg__Obstacle__Sequence__init(shell_interfaces__msg__Obstacle__Sequence * array, size_t size);

/// Finalize array of msg/Obstacle messages.
/**
 * It calls
 * shell_interfaces__msg__Obstacle__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
void
shell_interfaces__msg__Obstacle__Sequence__fini(shell_interfaces__msg__Obstacle__Sequence * array);

/// Create array of msg/Obstacle messages.
/**
 * It allocates the memory for the array and calls
 * shell_interfaces__msg__Obstacle__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
shell_interfaces__msg__Obstacle__Sequence *
shell_interfaces__msg__Obstacle__Sequence__create(size_t size);

/// Destroy array of msg/Obstacle messages.
/**
 * It calls
 * shell_interfaces__msg__Obstacle__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
void
shell_interfaces__msg__Obstacle__Sequence__destroy(shell_interfaces__msg__Obstacle__Sequence * array);

/// Check for msg/Obstacle message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
bool
shell_interfaces__msg__Obstacle__Sequence__are_equal(const shell_interfaces__msg__Obstacle__Sequence * lhs, const shell_interfaces__msg__Obstacle__Sequence * rhs);

/// Copy an array of msg/Obstacle messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
bool
shell_interfaces__msg__Obstacle__Sequence__copy(
  const shell_interfaces__msg__Obstacle__Sequence * input,
  shell_interfaces__msg__Obstacle__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SHELL_INTERFACES__MSG__DETAIL__OBSTACLE__FUNCTIONS_H_
