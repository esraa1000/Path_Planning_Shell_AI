// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from shell_interfaces:msg/Boundary.idl
// generated code does not contain a copyright notice
#include "shell_interfaces/msg/detail/boundary__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `points`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
shell_interfaces__msg__Boundary__init(shell_interfaces__msg__Boundary * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    shell_interfaces__msg__Boundary__fini(msg);
    return false;
  }
  // points
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->points, 0)) {
    shell_interfaces__msg__Boundary__fini(msg);
    return false;
  }
  return true;
}

void
shell_interfaces__msg__Boundary__fini(shell_interfaces__msg__Boundary * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // points
  geometry_msgs__msg__Point__Sequence__fini(&msg->points);
}

bool
shell_interfaces__msg__Boundary__are_equal(const shell_interfaces__msg__Boundary * lhs, const shell_interfaces__msg__Boundary * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // points
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->points), &(rhs->points)))
  {
    return false;
  }
  return true;
}

bool
shell_interfaces__msg__Boundary__copy(
  const shell_interfaces__msg__Boundary * input,
  shell_interfaces__msg__Boundary * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // points
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->points), &(output->points)))
  {
    return false;
  }
  return true;
}

shell_interfaces__msg__Boundary *
shell_interfaces__msg__Boundary__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  shell_interfaces__msg__Boundary * msg = (shell_interfaces__msg__Boundary *)allocator.allocate(sizeof(shell_interfaces__msg__Boundary), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(shell_interfaces__msg__Boundary));
  bool success = shell_interfaces__msg__Boundary__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
shell_interfaces__msg__Boundary__destroy(shell_interfaces__msg__Boundary * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    shell_interfaces__msg__Boundary__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
shell_interfaces__msg__Boundary__Sequence__init(shell_interfaces__msg__Boundary__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  shell_interfaces__msg__Boundary * data = NULL;

  if (size) {
    data = (shell_interfaces__msg__Boundary *)allocator.zero_allocate(size, sizeof(shell_interfaces__msg__Boundary), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = shell_interfaces__msg__Boundary__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        shell_interfaces__msg__Boundary__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
shell_interfaces__msg__Boundary__Sequence__fini(shell_interfaces__msg__Boundary__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      shell_interfaces__msg__Boundary__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

shell_interfaces__msg__Boundary__Sequence *
shell_interfaces__msg__Boundary__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  shell_interfaces__msg__Boundary__Sequence * array = (shell_interfaces__msg__Boundary__Sequence *)allocator.allocate(sizeof(shell_interfaces__msg__Boundary__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = shell_interfaces__msg__Boundary__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
shell_interfaces__msg__Boundary__Sequence__destroy(shell_interfaces__msg__Boundary__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    shell_interfaces__msg__Boundary__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
shell_interfaces__msg__Boundary__Sequence__are_equal(const shell_interfaces__msg__Boundary__Sequence * lhs, const shell_interfaces__msg__Boundary__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!shell_interfaces__msg__Boundary__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
shell_interfaces__msg__Boundary__Sequence__copy(
  const shell_interfaces__msg__Boundary__Sequence * input,
  shell_interfaces__msg__Boundary__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(shell_interfaces__msg__Boundary);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    shell_interfaces__msg__Boundary * data =
      (shell_interfaces__msg__Boundary *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!shell_interfaces__msg__Boundary__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          shell_interfaces__msg__Boundary__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!shell_interfaces__msg__Boundary__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
