// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from shell_interfaces:msg/Trajectory.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "shell_interfaces/msg/detail/trajectory__rosidl_typesupport_introspection_c.h"
#include "shell_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "shell_interfaces/msg/detail/trajectory__functions.h"
#include "shell_interfaces/msg/detail/trajectory__struct.h"


// Include directives for member types
// Member `points`
#include "shell_interfaces/msg/trajectory_point.h"
// Member `points`
#include "shell_interfaces/msg/detail/trajectory_point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  shell_interfaces__msg__Trajectory__init(message_memory);
}

void shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_fini_function(void * message_memory)
{
  shell_interfaces__msg__Trajectory__fini(message_memory);
}

size_t shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__size_function__Trajectory__points(
  const void * untyped_member)
{
  const shell_interfaces__msg__TrajectoryPoint__Sequence * member =
    (const shell_interfaces__msg__TrajectoryPoint__Sequence *)(untyped_member);
  return member->size;
}

const void * shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__points(
  const void * untyped_member, size_t index)
{
  const shell_interfaces__msg__TrajectoryPoint__Sequence * member =
    (const shell_interfaces__msg__TrajectoryPoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void * shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__points(
  void * untyped_member, size_t index)
{
  shell_interfaces__msg__TrajectoryPoint__Sequence * member =
    (shell_interfaces__msg__TrajectoryPoint__Sequence *)(untyped_member);
  return &member->data[index];
}

void shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__fetch_function__Trajectory__points(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const shell_interfaces__msg__TrajectoryPoint * item =
    ((const shell_interfaces__msg__TrajectoryPoint *)
    shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__points(untyped_member, index));
  shell_interfaces__msg__TrajectoryPoint * value =
    (shell_interfaces__msg__TrajectoryPoint *)(untyped_value);
  *value = *item;
}

void shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__assign_function__Trajectory__points(
  void * untyped_member, size_t index, const void * untyped_value)
{
  shell_interfaces__msg__TrajectoryPoint * item =
    ((shell_interfaces__msg__TrajectoryPoint *)
    shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__points(untyped_member, index));
  const shell_interfaces__msg__TrajectoryPoint * value =
    (const shell_interfaces__msg__TrajectoryPoint *)(untyped_value);
  *item = *value;
}

bool shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__resize_function__Trajectory__points(
  void * untyped_member, size_t size)
{
  shell_interfaces__msg__TrajectoryPoint__Sequence * member =
    (shell_interfaces__msg__TrajectoryPoint__Sequence *)(untyped_member);
  shell_interfaces__msg__TrajectoryPoint__Sequence__fini(member);
  return shell_interfaces__msg__TrajectoryPoint__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_member_array[1] = {
  {
    "points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(shell_interfaces__msg__Trajectory, points),  // bytes offset in struct
    NULL,  // default value
    shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__size_function__Trajectory__points,  // size() function pointer
    shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__points,  // get_const(index) function pointer
    shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__points,  // get(index) function pointer
    shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__fetch_function__Trajectory__points,  // fetch(index, &value) function pointer
    shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__assign_function__Trajectory__points,  // assign(index, value) function pointer
    shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__resize_function__Trajectory__points  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_members = {
  "shell_interfaces__msg",  // message namespace
  "Trajectory",  // message name
  1,  // number of fields
  sizeof(shell_interfaces__msg__Trajectory),
  shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_member_array,  // message members
  shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_init_function,  // function to initialize message memory (memory has to be allocated)
  shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_type_support_handle = {
  0,
  &shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_shell_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, shell_interfaces, msg, Trajectory)() {
  shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, shell_interfaces, msg, TrajectoryPoint)();
  if (!shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_type_support_handle.typesupport_identifier) {
    shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &shell_interfaces__msg__Trajectory__rosidl_typesupport_introspection_c__Trajectory_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
