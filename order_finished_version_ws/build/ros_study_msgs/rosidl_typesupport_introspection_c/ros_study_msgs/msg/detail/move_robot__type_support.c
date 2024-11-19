// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ros_study_msgs:msg/MoveRobot.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ros_study_msgs/msg/detail/move_robot__rosidl_typesupport_introspection_c.h"
#include "ros_study_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ros_study_msgs/msg/detail/move_robot__functions.h"
#include "ros_study_msgs/msg/detail/move_robot__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ros_study_msgs__msg__MoveRobot__rosidl_typesupport_introspection_c__MoveRobot_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ros_study_msgs__msg__MoveRobot__init(message_memory);
}

void ros_study_msgs__msg__MoveRobot__rosidl_typesupport_introspection_c__MoveRobot_fini_function(void * message_memory)
{
  ros_study_msgs__msg__MoveRobot__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ros_study_msgs__msg__MoveRobot__rosidl_typesupport_introspection_c__MoveRobot_message_member_array[1] = {
  {
    "topic_move_robot",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros_study_msgs__msg__MoveRobot, topic_move_robot),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ros_study_msgs__msg__MoveRobot__rosidl_typesupport_introspection_c__MoveRobot_message_members = {
  "ros_study_msgs__msg",  // message namespace
  "MoveRobot",  // message name
  1,  // number of fields
  sizeof(ros_study_msgs__msg__MoveRobot),
  ros_study_msgs__msg__MoveRobot__rosidl_typesupport_introspection_c__MoveRobot_message_member_array,  // message members
  ros_study_msgs__msg__MoveRobot__rosidl_typesupport_introspection_c__MoveRobot_init_function,  // function to initialize message memory (memory has to be allocated)
  ros_study_msgs__msg__MoveRobot__rosidl_typesupport_introspection_c__MoveRobot_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ros_study_msgs__msg__MoveRobot__rosidl_typesupport_introspection_c__MoveRobot_message_type_support_handle = {
  0,
  &ros_study_msgs__msg__MoveRobot__rosidl_typesupport_introspection_c__MoveRobot_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros_study_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros_study_msgs, msg, MoveRobot)() {
  if (!ros_study_msgs__msg__MoveRobot__rosidl_typesupport_introspection_c__MoveRobot_message_type_support_handle.typesupport_identifier) {
    ros_study_msgs__msg__MoveRobot__rosidl_typesupport_introspection_c__MoveRobot_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ros_study_msgs__msg__MoveRobot__rosidl_typesupport_introspection_c__MoveRobot_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
