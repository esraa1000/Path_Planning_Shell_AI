// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from shell_interfaces:msg/Boundary.idl
// generated code does not contain a copyright notice

#ifndef SHELL_INTERFACES__MSG__DETAIL__BOUNDARY__FUNCTIONS_H_
#define SHELL_INTERFACES__MSG__DETAIL__BOUNDARY__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "shell_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "shell_interfaces/msg/detail/boundary__struct.h"

/// Initialize msg/Boundary message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * shell_interfaces__msg__Boundary
 * )) before or use
 * shell_interfaces__msg__Boundary__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
bool
shell_interfaces__msg__Boundary__init(shell_interfaces__msg__Boundary * msg);

/// Finalize msg/Boundary message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
void
shell_interfaces__msg__Boundary__fini(shell_interfaces__msg__Boundary * msg);

/// Create msg/Boundary message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * shell_interfaces__msg__Boundary__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
shell_interfaces__msg__Boundary *
shell_interfaces__msg__Boundary__create();

/// Destroy msg/Boundary message.
/**
 * It calls
 * shell_interfaces__msg__Boundary__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
void
shell_interfaces__msg__Boundary__destroy(shell_interfaces__msg__Boundary * msg);

/// Check for msg/Boundary message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
bool
shell_interfaces__msg__Boundary__are_equal(const shell_interfaces__msg__Boundary * lhs, const shell_interfaces__msg__Boundary * rhs);

/// Copy a msg/Boundary message.
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
shell_interfaces__msg__Boundary__copy(
  const shell_interfaces__msg__Boundary * input,
  shell_interfaces__msg__Boundary * output);

/// Initialize array of msg/Boundary messages.
/**
 * It allocates the memory for the number of elements and calls
 * shell_interfaces__msg__Boundary__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
bool
shell_interfaces__msg__Boundary__Sequence__init(shell_interfaces__msg__Boundary__Sequence * array, size_t size);

/// Finalize array of msg/Boundary messages.
/**
 * It calls
 * shell_interfaces__msg__Boundary__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
void
shell_interfaces__msg__Boundary__Sequence__fini(shell_interfaces__msg__Boundary__Sequence * array);

/// Create array of msg/Boundary messages.
/**
 * It allocates the memory for the array and calls
 * shell_interfaces__msg__Boundary__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
shell_interfaces__msg__Boundary__Sequence *
shell_interfaces__msg__Boundary__Sequence__create(size_t size);

/// Destroy array of msg/Boundary messages.
/**
 * It calls
 * shell_interfaces__msg__Boundary__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
void
shell_interfaces__msg__Boundary__Sequence__destroy(shell_interfaces__msg__Boundary__Sequence * array);

/// Check for msg/Boundary message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_shell_interfaces
bool
shell_interfaces__msg__Boundary__Sequence__are_equal(const shell_interfaces__msg__Boundary__Sequence * lhs, const shell_interfaces__msg__Boundary__Sequence * rhs);

/// Copy an array of msg/Boundary messages.
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
shell_interfaces__msg__Boundary__Sequence__copy(
  const shell_interfaces__msg__Boundary__Sequence * input,
  shell_interfaces__msg__Boundary__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SHELL_INTERFACES__MSG__DETAIL__BOUNDARY__FUNCTIONS_H_
