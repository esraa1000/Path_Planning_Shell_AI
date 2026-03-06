// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from shell_interfaces:msg/Boundary.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "shell_interfaces/msg/detail/boundary__rosidl_typesupport_introspection_c.h"
#include "shell_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "shell_interfaces/msg/detail/boundary__functions.h"
#include "shell_interfaces/msg/detail/boundary__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `points`
#include "geometry_msgs/msg/point.h"
// Member `points`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__Boundary_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  shell_interfaces__msg__Boundary__init(message_memory);
}

void shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__Boundary_fini_function(void * message_memory)
{
  shell_interfaces__msg__Boundary__fini(message_memory);
}

size_t shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__size_function__Boundary__points(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__get_const_function__Boundary__points(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__get_function__Boundary__points(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__fetch_function__Boundary__points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const geometry_msgs__msg__Point * item =
    ((const geometry_msgs__msg__Point *)
    shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__get_const_function__Boundary__points(untyped_member, index));
  geometry_msgs__msg__Point * value =
    (geometry_msgs__msg__Point *)(untyped_value);
  *value = *item;
}

void shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__assign_function__Boundary__points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  geometry_msgs__msg__Point * item =
    ((geometry_msgs__msg__Point *)
    shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__get_function__Boundary__points(untyped_member, index));
  const geometry_msgs__msg__Point * value =
    (const geometry_msgs__msg__Point *)(untyped_value);
  *item = *value;
}

bool shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__resize_function__Boundary__points(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__Boundary_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(shell_interfaces__msg__Boundary, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(shell_interfaces__msg__Boundary, points),  // bytes offset in struct
    NULL,  // default value
    shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__size_function__Boundary__points,  // size() function pointer
    shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__get_const_function__Boundary__points,  // get_const(index) function pointer
    shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__get_function__Boundary__points,  // get(index) function pointer
    shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__fetch_function__Boundary__points,  // fetch(index, &value) function pointer
    shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__assign_function__Boundary__points,  // assign(index, value) function pointer
    shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__resize_function__Boundary__points  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__Boundary_message_members = {
  "shell_interfaces__msg",  // message namespace
  "Boundary",  // message name
  2,  // number of fields
  sizeof(shell_interfaces__msg__Boundary),
  shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__Boundary_message_member_array,  // message members
  shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__Boundary_init_function,  // function to initialize message memory (memory has to be allocated)
  shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__Boundary_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__Boundary_message_type_support_handle = {
  0,
  &shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__Boundary_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_shell_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, shell_interfaces, msg, Boundary)() {
  shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__Boundary_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__Boundary_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__Boundary_message_type_support_handle.typesupport_identifier) {
    shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__Boundary_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &shell_interfaces__msg__Boundary__rosidl_typesupport_introspection_c__Boundary_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
