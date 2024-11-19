// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros_study_msgs:msg/MoveRobot.idl
// generated code does not contain a copyright notice

#ifndef ROS_STUDY_MSGS__MSG__DETAIL__MOVE_ROBOT__STRUCT_H_
#define ROS_STUDY_MSGS__MSG__DETAIL__MOVE_ROBOT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/MoveRobot in the package ros_study_msgs.
typedef struct ros_study_msgs__msg__MoveRobot
{
  int8_t topic_move_robot;
} ros_study_msgs__msg__MoveRobot;

// Struct for a sequence of ros_study_msgs__msg__MoveRobot.
typedef struct ros_study_msgs__msg__MoveRobot__Sequence
{
  ros_study_msgs__msg__MoveRobot * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros_study_msgs__msg__MoveRobot__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS_STUDY_MSGS__MSG__DETAIL__MOVE_ROBOT__STRUCT_H_
