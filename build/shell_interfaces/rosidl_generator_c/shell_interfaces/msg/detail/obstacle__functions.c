// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from shell_interfaces:msg/Obstacle.idl
// generated code does not contain a copyright notice
#include "shell_interfaces/msg/detail/obstacle__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `center`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
shell_interfaces__msg__Obstacle__init(shell_interfaces__msg__Obstacle * msg)
{
  if (!msg) {
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__init(&msg->center)) {
    shell_interfaces__msg__Obstacle__fini(msg);
    return false;
  }
  // radius
  return true;
}

void
shell_interfaces__msg__Obstacle__fini(shell_interfaces__msg__Obstacle * msg)
{
  if (!msg) {
    return;
  }
  // center
  geometry_msgs__msg__Point__fini(&msg->center);
  // radius
}

bool
shell_interfaces__msg__Obstacle__are_equal(const shell_interfaces__msg__Obstacle * lhs, const shell_interfaces__msg__Obstacle * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->center), &(rhs->center)))
  {
    return false;
  }
  // radius
  if (lhs->radius != rhs->radius) {
    return false;
  }
  return true;
}

bool
shell_interfaces__msg__Obstacle__copy(
  const shell_interfaces__msg__Obstacle * input,
  shell_interfaces__msg__Obstacle * output)
{
  if (!input || !output) {
    return false;
  }
  // center
  if (!geometry_msgs__msg__Point__copy(
      &(input->center), &(output->center)))
  {
    return false;
  }
  // radius
  output->radius = input->radius;
  return true;
}

shell_interfaces__msg__Obstacle *
shell_interfaces__msg__Obstacle__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  shell_interfaces__msg__Obstacle * msg = (shell_interfaces__msg__Obstacle *)allocator.allocate(sizeof(shell_interfaces__msg__Obstacle), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(shell_interfaces__msg__Obstacle));
  bool success = shell_interfaces__msg__Obstacle__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
shell_interfaces__msg__Obstacle__destroy(shell_interfaces__msg__Obstacle * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    shell_interfaces__msg__Obstacle__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
shell_interfaces__msg__Obstacle__Sequence__init(shell_interfaces__msg__Obstacle__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  shell_interfaces__msg__Obstacle * data = NULL;

  if (size) {
    data = (shell_interfaces__msg__Obstacle *)allocator.zero_allocate(size, sizeof(shell_interfaces__msg__Obstacle), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = shell_interfaces__msg__Obstacle__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        shell_interfaces__msg__Obstacle__fini(&data[i - 1]);
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
shell_interfaces__msg__Obstacle__Sequence__fini(shell_interfaces__msg__Obstacle__Sequence * array)
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
      shell_interfaces__msg__Obstacle__fini(&array->data[i]);
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

shell_interfaces__msg__Obstacle__Sequence *
shell_interfaces__msg__Obstacle__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  shell_interfaces__msg__Obstacle__Sequence * array = (shell_interfaces__msg__Obstacle__Sequence *)allocator.allocate(sizeof(shell_interfaces__msg__Obstacle__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = shell_interfaces__msg__Obstacle__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
shell_interfaces__msg__Obstacle__Sequence__destroy(shell_interfaces__msg__Obstacle__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    shell_interfaces__msg__Obstacle__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
shell_interfaces__msg__Obstacle__Sequence__are_equal(const shell_interfaces__msg__Obstacle__Sequence * lhs, const shell_interfaces__msg__Obstacle__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!shell_interfaces__msg__Obstacle__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
shell_interfaces__msg__Obstacle__Sequence__copy(
  const shell_interfaces__msg__Obstacle__Sequence * input,
  shell_interfaces__msg__Obstacle__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(shell_interfaces__msg__Obstacle);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    shell_interfaces__msg__Obstacle * data =
      (shell_interfaces__msg__Obstacle *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!shell_interfaces__msg__Obstacle__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          shell_interfaces__msg__Obstacle__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!shell_interfaces__msg__Obstacle__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
