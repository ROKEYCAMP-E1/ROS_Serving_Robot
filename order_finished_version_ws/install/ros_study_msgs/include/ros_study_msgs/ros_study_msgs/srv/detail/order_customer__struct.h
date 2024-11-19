// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ros_study_msgs:srv/OrderCustomer.idl
// generated code does not contain a copyright notice

#ifndef ROS_STUDY_MSGS__SRV__DETAIL__ORDER_CUSTOMER__STRUCT_H_
#define ROS_STUDY_MSGS__SRV__DETAIL__ORDER_CUSTOMER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'menu_num'
// Member 'quantity_num'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/OrderCustomer in the package ros_study_msgs.
typedef struct ros_study_msgs__srv__OrderCustomer_Request
{
  /// 음식 번호
  rosidl_runtime_c__int32__Sequence menu_num;
  /// 음식 수량
  rosidl_runtime_c__int32__Sequence quantity_num;
  /// 테이블 넘버
  int8_t table_number;
  int8_t order_round;
} ros_study_msgs__srv__OrderCustomer_Request;

// Struct for a sequence of ros_study_msgs__srv__OrderCustomer_Request.
typedef struct ros_study_msgs__srv__OrderCustomer_Request__Sequence
{
  ros_study_msgs__srv__OrderCustomer_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros_study_msgs__srv__OrderCustomer_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/OrderCustomer in the package ros_study_msgs.
typedef struct ros_study_msgs__srv__OrderCustomer_Response
{
  int8_t order_check;
} ros_study_msgs__srv__OrderCustomer_Response;

// Struct for a sequence of ros_study_msgs__srv__OrderCustomer_Response.
typedef struct ros_study_msgs__srv__OrderCustomer_Response__Sequence
{
  ros_study_msgs__srv__OrderCustomer_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ros_study_msgs__srv__OrderCustomer_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // ROS_STUDY_MSGS__SRV__DETAIL__ORDER_CUSTOMER__STRUCT_H_
