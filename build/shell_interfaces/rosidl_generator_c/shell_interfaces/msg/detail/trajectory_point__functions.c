// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from shell_interfaces:msg/TrajectoryPoint.idl
// generated code does not contain a copyright notice
#include "shell_interfaces/msg/detail/trajectory_point__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
shell_interfaces__msg__TrajectoryPoint__init(shell_interfaces__msg__TrajectoryPoint * msg)
{
  if (!msg) {
    return false;
  }
  // x
  // y
  // theta
  // v
  return true;
}

void
shell_interfaces__msg__TrajectoryPoint__fini(shell_interfaces__msg__TrajectoryPoint * msg)
{
  if (!msg) {
    return;
  }
  // x
  // y
  // theta
  // v
}

bool
shell_interfaces__msg__TrajectoryPoint__are_equal(const shell_interfaces__msg__TrajectoryPoint * lhs, const shell_interfaces__msg__TrajectoryPoint * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  // theta
  if (lhs->theta != rhs->theta) {
    return false;
  }
  // v
  if (lhs->v != rhs->v) {
    return false;
  }
  return true;
}

bool
shell_interfaces__msg__TrajectoryPoint__copy(
  const shell_interfaces__msg__TrajectoryPoint * input,
  shell_interfaces__msg__TrajectoryPoint * output)
{
  if (!input || !output) {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  // theta
  output->theta = input->theta;
  // v
  output->v = input->v;
  return true;
}

shell_interfaces__msg__TrajectoryPoint *
shell_interfaces__msg__TrajectoryPoint__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  shell_interfaces__msg__TrajectoryPoint * msg = (shell_interfaces__msg__TrajectoryPoint *)allocator.allocate(sizeof(shell_interfaces__msg__TrajectoryPoint), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(shell_interfaces__msg__TrajectoryPoint));
  bool success = shell_interfaces__msg__TrajectoryPoint__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
shell_interfaces__msg__TrajectoryPoint__destroy(shell_interfaces__msg__TrajectoryPoint * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    shell_interfaces__msg__TrajectoryPoint__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
shell_interfaces__msg__TrajectoryPoint__Sequence__init(shell_interfaces__msg__TrajectoryPoint__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  shell_interfaces__msg__TrajectoryPoint * data = NULL;

  if (size) {
    data = (shell_interfaces__msg__TrajectoryPoint *)allocator.zero_allocate(size, sizeof(shell_interfaces__msg__TrajectoryPoint), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = shell_interfaces__msg__TrajectoryPoint__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        shell_interfaces__msg__TrajectoryPoint__fini(&data[i - 1]);
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
shell_interfaces__msg__TrajectoryPoint__Sequence__fini(shell_interfaces__msg__TrajectoryPoint__Sequence * array)
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
      shell_interfaces__msg__TrajectoryPoint__fini(&array->data[i]);
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

shell_interfaces__msg__TrajectoryPoint__Sequence *
shell_interfaces__msg__TrajectoryPoint__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  shell_interfaces__msg__TrajectoryPoint__Sequence * array = (shell_interfaces__msg__TrajectoryPoint__Sequence *)allocator.allocate(sizeof(shell_interfaces__msg__TrajectoryPoint__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = shell_interfaces__msg__TrajectoryPoint__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
shell_interfaces__msg__TrajectoryPoint__Sequence__destroy(shell_interfaces__msg__TrajectoryPoint__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    shell_interfaces__msg__TrajectoryPoint__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
shell_interfaces__msg__TrajectoryPoint__Sequence__are_equal(const shell_interfaces__msg__TrajectoryPoint__Sequence * lhs, const shell_interfaces__msg__TrajectoryPoint__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!shell_interfaces__msg__TrajectoryPoint__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
shell_interfaces__msg__TrajectoryPoint__Sequence__copy(
  const shell_interfaces__msg__TrajectoryPoint__Sequence * input,
  shell_interfaces__msg__TrajectoryPoint__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(shell_interfaces__msg__TrajectoryPoint);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    shell_interfaces__msg__TrajectoryPoint * data =
      (shell_interfaces__msg__TrajectoryPoint *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!shell_interfaces__msg__TrajectoryPoint__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          shell_interfaces__msg__TrajectoryPoint__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!shell_interfaces__msg__TrajectoryPoint__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
