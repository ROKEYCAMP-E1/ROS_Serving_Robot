// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ros_study_msgs:srv/OrderCustomer.idl
// generated code does not contain a copyright notice
#include "ros_study_msgs/srv/detail/order_customer__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ros_study_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ros_study_msgs/srv/detail/order_customer__struct.h"
#include "ros_study_msgs/srv/detail/order_customer__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // menu_num, quantity_num
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // menu_num, quantity_num

// forward declare type support functions


using _OrderCustomer_Request__ros_msg_type = ros_study_msgs__srv__OrderCustomer_Request;

static bool _OrderCustomer_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _OrderCustomer_Request__ros_msg_type * ros_message = static_cast<const _OrderCustomer_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: menu_num
  {
    size_t size = ros_message->menu_num.size;
    auto array_ptr = ros_message->menu_num.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: quantity_num
  {
    size_t size = ros_message->quantity_num.size;
    auto array_ptr = ros_message->quantity_num.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: table_number
  {
    cdr << ros_message->table_number;
  }

  // Field name: order_round
  {
    cdr << ros_message->order_round;
  }

  return true;
}

static bool _OrderCustomer_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _OrderCustomer_Request__ros_msg_type * ros_message = static_cast<_OrderCustomer_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: menu_num
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->menu_num.data) {
      rosidl_runtime_c__int32__Sequence__fini(&ros_message->menu_num);
    }
    if (!rosidl_runtime_c__int32__Sequence__init(&ros_message->menu_num, size)) {
      fprintf(stderr, "failed to create array for field 'menu_num'");
      return false;
    }
    auto array_ptr = ros_message->menu_num.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: quantity_num
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->quantity_num.data) {
      rosidl_runtime_c__int32__Sequence__fini(&ros_message->quantity_num);
    }
    if (!rosidl_runtime_c__int32__Sequence__init(&ros_message->quantity_num, size)) {
      fprintf(stderr, "failed to create array for field 'quantity_num'");
      return false;
    }
    auto array_ptr = ros_message->quantity_num.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: table_number
  {
    cdr >> ros_message->table_number;
  }

  // Field name: order_round
  {
    cdr >> ros_message->order_round;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros_study_msgs
size_t get_serialized_size_ros_study_msgs__srv__OrderCustomer_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _OrderCustomer_Request__ros_msg_type * ros_message = static_cast<const _OrderCustomer_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name menu_num
  {
    size_t array_size = ros_message->menu_num.size;
    auto array_ptr = ros_message->menu_num.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name quantity_num
  {
    size_t array_size = ros_message->quantity_num.size;
    auto array_ptr = ros_message->quantity_num.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name table_number
  {
    size_t item_size = sizeof(ros_message->table_number);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name order_round
  {
    size_t item_size = sizeof(ros_message->order_round);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _OrderCustomer_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ros_study_msgs__srv__OrderCustomer_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros_study_msgs
size_t max_serialized_size_ros_study_msgs__srv__OrderCustomer_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: menu_num
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: quantity_num
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint32_t);
    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: table_number
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: order_round
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ros_study_msgs__srv__OrderCustomer_Request;
    is_plain =
      (
      offsetof(DataType, order_round) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _OrderCustomer_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ros_study_msgs__srv__OrderCustomer_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_OrderCustomer_Request = {
  "ros_study_msgs::srv",
  "OrderCustomer_Request",
  _OrderCustomer_Request__cdr_serialize,
  _OrderCustomer_Request__cdr_deserialize,
  _OrderCustomer_Request__get_serialized_size,
  _OrderCustomer_Request__max_serialized_size
};

static rosidl_message_type_support_t _OrderCustomer_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_OrderCustomer_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros_study_msgs, srv, OrderCustomer_Request)() {
  return &_OrderCustomer_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "ros_study_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "ros_study_msgs/srv/detail/order_customer__struct.h"
// already included above
// #include "ros_study_msgs/srv/detail/order_customer__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _OrderCustomer_Response__ros_msg_type = ros_study_msgs__srv__OrderCustomer_Response;

static bool _OrderCustomer_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _OrderCustomer_Response__ros_msg_type * ros_message = static_cast<const _OrderCustomer_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: order_check
  {
    cdr << ros_message->order_check;
  }

  return true;
}

static bool _OrderCustomer_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _OrderCustomer_Response__ros_msg_type * ros_message = static_cast<_OrderCustomer_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: order_check
  {
    cdr >> ros_message->order_check;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros_study_msgs
size_t get_serialized_size_ros_study_msgs__srv__OrderCustomer_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _OrderCustomer_Response__ros_msg_type * ros_message = static_cast<const _OrderCustomer_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name order_check
  {
    size_t item_size = sizeof(ros_message->order_check);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _OrderCustomer_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ros_study_msgs__srv__OrderCustomer_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ros_study_msgs
size_t max_serialized_size_ros_study_msgs__srv__OrderCustomer_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: order_check
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ros_study_msgs__srv__OrderCustomer_Response;
    is_plain =
      (
      offsetof(DataType, order_check) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _OrderCustomer_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ros_study_msgs__srv__OrderCustomer_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_OrderCustomer_Response = {
  "ros_study_msgs::srv",
  "OrderCustomer_Response",
  _OrderCustomer_Response__cdr_serialize,
  _OrderCustomer_Response__cdr_deserialize,
  _OrderCustomer_Response__get_serialized_size,
  _OrderCustomer_Response__max_serialized_size
};

static rosidl_message_type_support_t _OrderCustomer_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_OrderCustomer_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros_study_msgs, srv, OrderCustomer_Response)() {
  return &_OrderCustomer_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "ros_study_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ros_study_msgs/srv/order_customer.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t OrderCustomer__callbacks = {
  "ros_study_msgs::srv",
  "OrderCustomer",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros_study_msgs, srv, OrderCustomer_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros_study_msgs, srv, OrderCustomer_Response)(),
};

static rosidl_service_type_support_t OrderCustomer__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &OrderCustomer__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ros_study_msgs, srv, OrderCustomer)() {
  return &OrderCustomer__handle;
}

#if defined(__cplusplus)
}
#endif
