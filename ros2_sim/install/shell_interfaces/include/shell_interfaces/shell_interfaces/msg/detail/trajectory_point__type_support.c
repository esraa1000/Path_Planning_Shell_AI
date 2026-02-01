// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from shell_interfaces:msg/TrajectoryPoint.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "shell_interfaces/msg/detail/trajectory_point__rosidl_typesupport_introspection_c.h"
#include "shell_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "shell_interfaces/msg/detail/trajectory_point__functions.h"
#include "shell_interfaces/msg/detail/trajectory_point__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void shell_interfaces__msg__TrajectoryPoint__rosidl_typesupport_introspection_c__TrajectoryPoint_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  shell_interfaces__msg__TrajectoryPoint__init(message_memory);
}

void shell_interfaces__msg__TrajectoryPoint__rosidl_typesupport_introspection_c__TrajectoryPoint_fini_function(void * message_memory)
{
  shell_interfaces__msg__TrajectoryPoint__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember shell_interfaces__msg__TrajectoryPoint__rosidl_typesupport_introspection_c__TrajectoryPoint_message_member_array[4] = {
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(shell_interfaces__msg__TrajectoryPoint, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(shell_interfaces__msg__TrajectoryPoint, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "theta",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(shell_interfaces__msg__TrajectoryPoint, theta),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "v",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(shell_interfaces__msg__TrajectoryPoint, v),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers shell_interfaces__msg__TrajectoryPoint__rosidl_typesupport_introspection_c__TrajectoryPoint_message_members = {
  "shell_interfaces__msg",  // message namespace
  "TrajectoryPoint",  // message name
  4,  // number of fields
  sizeof(shell_interfaces__msg__TrajectoryPoint),
  shell_interfaces__msg__TrajectoryPoint__rosidl_typesupport_introspection_c__TrajectoryPoint_message_member_array,  // message members
  shell_interfaces__msg__TrajectoryPoint__rosidl_typesupport_introspection_c__TrajectoryPoint_init_function,  // function to initialize message memory (memory has to be allocated)
  shell_interfaces__msg__TrajectoryPoint__rosidl_typesupport_introspection_c__TrajectoryPoint_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t shell_interfaces__msg__TrajectoryPoint__rosidl_typesupport_introspection_c__TrajectoryPoint_message_type_support_handle = {
  0,
  &shell_interfaces__msg__TrajectoryPoint__rosidl_typesupport_introspection_c__TrajectoryPoint_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_shell_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, shell_interfaces, msg, TrajectoryPoint)() {
  if (!shell_interfaces__msg__TrajectoryPoint__rosidl_typesupport_introspection_c__TrajectoryPoint_message_type_support_handle.typesupport_identifier) {
    shell_interfaces__msg__TrajectoryPoint__rosidl_typesupport_introspection_c__TrajectoryPoint_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &shell_interfaces__msg__TrajectoryPoint__rosidl_typesupport_introspection_c__TrajectoryPoint_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
