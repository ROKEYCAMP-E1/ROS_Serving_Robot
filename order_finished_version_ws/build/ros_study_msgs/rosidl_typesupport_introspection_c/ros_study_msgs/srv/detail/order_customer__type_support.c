// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ros_study_msgs:srv/OrderCustomer.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ros_study_msgs/srv/detail/order_customer__rosidl_typesupport_introspection_c.h"
#include "ros_study_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ros_study_msgs/srv/detail/order_customer__functions.h"
#include "ros_study_msgs/srv/detail/order_customer__struct.h"


// Include directives for member types
// Member `menu_num`
// Member `quantity_num`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__OrderCustomer_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ros_study_msgs__srv__OrderCustomer_Request__init(message_memory);
}

void ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__OrderCustomer_Request_fini_function(void * message_memory)
{
  ros_study_msgs__srv__OrderCustomer_Request__fini(message_memory);
}

size_t ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__size_function__OrderCustomer_Request__menu_num(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__get_const_function__OrderCustomer_Request__menu_num(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__get_function__OrderCustomer_Request__menu_num(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__fetch_function__OrderCustomer_Request__menu_num(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__get_const_function__OrderCustomer_Request__menu_num(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__assign_function__OrderCustomer_Request__menu_num(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__get_function__OrderCustomer_Request__menu_num(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__resize_function__OrderCustomer_Request__menu_num(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

size_t ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__size_function__OrderCustomer_Request__quantity_num(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__get_const_function__OrderCustomer_Request__quantity_num(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__get_function__OrderCustomer_Request__quantity_num(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__fetch_function__OrderCustomer_Request__quantity_num(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__get_const_function__OrderCustomer_Request__quantity_num(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__assign_function__OrderCustomer_Request__quantity_num(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__get_function__OrderCustomer_Request__quantity_num(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__resize_function__OrderCustomer_Request__quantity_num(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__OrderCustomer_Request_message_member_array[4] = {
  {
    "menu_num",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros_study_msgs__srv__OrderCustomer_Request, menu_num),  // bytes offset in struct
    NULL,  // default value
    ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__size_function__OrderCustomer_Request__menu_num,  // size() function pointer
    ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__get_const_function__OrderCustomer_Request__menu_num,  // get_const(index) function pointer
    ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__get_function__OrderCustomer_Request__menu_num,  // get(index) function pointer
    ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__fetch_function__OrderCustomer_Request__menu_num,  // fetch(index, &value) function pointer
    ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__assign_function__OrderCustomer_Request__menu_num,  // assign(index, value) function pointer
    ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__resize_function__OrderCustomer_Request__menu_num  // resize(index) function pointer
  },
  {
    "quantity_num",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros_study_msgs__srv__OrderCustomer_Request, quantity_num),  // bytes offset in struct
    NULL,  // default value
    ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__size_function__OrderCustomer_Request__quantity_num,  // size() function pointer
    ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__get_const_function__OrderCustomer_Request__quantity_num,  // get_const(index) function pointer
    ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__get_function__OrderCustomer_Request__quantity_num,  // get(index) function pointer
    ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__fetch_function__OrderCustomer_Request__quantity_num,  // fetch(index, &value) function pointer
    ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__assign_function__OrderCustomer_Request__quantity_num,  // assign(index, value) function pointer
    ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__resize_function__OrderCustomer_Request__quantity_num  // resize(index) function pointer
  },
  {
    "table_number",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros_study_msgs__srv__OrderCustomer_Request, table_number),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "order_round",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros_study_msgs__srv__OrderCustomer_Request, order_round),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__OrderCustomer_Request_message_members = {
  "ros_study_msgs__srv",  // message namespace
  "OrderCustomer_Request",  // message name
  4,  // number of fields
  sizeof(ros_study_msgs__srv__OrderCustomer_Request),
  ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__OrderCustomer_Request_message_member_array,  // message members
  ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__OrderCustomer_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__OrderCustomer_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__OrderCustomer_Request_message_type_support_handle = {
  0,
  &ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__OrderCustomer_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros_study_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros_study_msgs, srv, OrderCustomer_Request)() {
  if (!ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__OrderCustomer_Request_message_type_support_handle.typesupport_identifier) {
    ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__OrderCustomer_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ros_study_msgs__srv__OrderCustomer_Request__rosidl_typesupport_introspection_c__OrderCustomer_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "ros_study_msgs/srv/detail/order_customer__rosidl_typesupport_introspection_c.h"
// already included above
// #include "ros_study_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "ros_study_msgs/srv/detail/order_customer__functions.h"
// already included above
// #include "ros_study_msgs/srv/detail/order_customer__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ros_study_msgs__srv__OrderCustomer_Response__rosidl_typesupport_introspection_c__OrderCustomer_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ros_study_msgs__srv__OrderCustomer_Response__init(message_memory);
}

void ros_study_msgs__srv__OrderCustomer_Response__rosidl_typesupport_introspection_c__OrderCustomer_Response_fini_function(void * message_memory)
{
  ros_study_msgs__srv__OrderCustomer_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ros_study_msgs__srv__OrderCustomer_Response__rosidl_typesupport_introspection_c__OrderCustomer_Response_message_member_array[1] = {
  {
    "order_check",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ros_study_msgs__srv__OrderCustomer_Response, order_check),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ros_study_msgs__srv__OrderCustomer_Response__rosidl_typesupport_introspection_c__OrderCustomer_Response_message_members = {
  "ros_study_msgs__srv",  // message namespace
  "OrderCustomer_Response",  // message name
  1,  // number of fields
  sizeof(ros_study_msgs__srv__OrderCustomer_Response),
  ros_study_msgs__srv__OrderCustomer_Response__rosidl_typesupport_introspection_c__OrderCustomer_Response_message_member_array,  // message members
  ros_study_msgs__srv__OrderCustomer_Response__rosidl_typesupport_introspection_c__OrderCustomer_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ros_study_msgs__srv__OrderCustomer_Response__rosidl_typesupport_introspection_c__OrderCustomer_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ros_study_msgs__srv__OrderCustomer_Response__rosidl_typesupport_introspection_c__OrderCustomer_Response_message_type_support_handle = {
  0,
  &ros_study_msgs__srv__OrderCustomer_Response__rosidl_typesupport_introspection_c__OrderCustomer_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros_study_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros_study_msgs, srv, OrderCustomer_Response)() {
  if (!ros_study_msgs__srv__OrderCustomer_Response__rosidl_typesupport_introspection_c__OrderCustomer_Response_message_type_support_handle.typesupport_identifier) {
    ros_study_msgs__srv__OrderCustomer_Response__rosidl_typesupport_introspection_c__OrderCustomer_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ros_study_msgs__srv__OrderCustomer_Response__rosidl_typesupport_introspection_c__OrderCustomer_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "ros_study_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "ros_study_msgs/srv/detail/order_customer__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers ros_study_msgs__srv__detail__order_customer__rosidl_typesupport_introspection_c__OrderCustomer_service_members = {
  "ros_study_msgs__srv",  // service namespace
  "OrderCustomer",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // ros_study_msgs__srv__detail__order_customer__rosidl_typesupport_introspection_c__OrderCustomer_Request_message_type_support_handle,
  NULL  // response message
  // ros_study_msgs__srv__detail__order_customer__rosidl_typesupport_introspection_c__OrderCustomer_Response_message_type_support_handle
};

static rosidl_service_type_support_t ros_study_msgs__srv__detail__order_customer__rosidl_typesupport_introspection_c__OrderCustomer_service_type_support_handle = {
  0,
  &ros_study_msgs__srv__detail__order_customer__rosidl_typesupport_introspection_c__OrderCustomer_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros_study_msgs, srv, OrderCustomer_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros_study_msgs, srv, OrderCustomer_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ros_study_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros_study_msgs, srv, OrderCustomer)() {
  if (!ros_study_msgs__srv__detail__order_customer__rosidl_typesupport_introspection_c__OrderCustomer_service_type_support_handle.typesupport_identifier) {
    ros_study_msgs__srv__detail__order_customer__rosidl_typesupport_introspection_c__OrderCustomer_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)ros_study_msgs__srv__detail__order_customer__rosidl_typesupport_introspection_c__OrderCustomer_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros_study_msgs, srv, OrderCustomer_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ros_study_msgs, srv, OrderCustomer_Response)()->data;
  }

  return &ros_study_msgs__srv__detail__order_customer__rosidl_typesupport_introspection_c__OrderCustomer_service_type_support_handle;
}
