// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros_study_msgs:srv/OrderCustomer.idl
// generated code does not contain a copyright notice
#include "ros_study_msgs/srv/detail/order_customer__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `menu_num`
// Member `quantity_num`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
ros_study_msgs__srv__OrderCustomer_Request__init(ros_study_msgs__srv__OrderCustomer_Request * msg)
{
  if (!msg) {
    return false;
  }
  // menu_num
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->menu_num, 0)) {
    ros_study_msgs__srv__OrderCustomer_Request__fini(msg);
    return false;
  }
  // quantity_num
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->quantity_num, 0)) {
    ros_study_msgs__srv__OrderCustomer_Request__fini(msg);
    return false;
  }
  // table_number
  // order_round
  return true;
}

void
ros_study_msgs__srv__OrderCustomer_Request__fini(ros_study_msgs__srv__OrderCustomer_Request * msg)
{
  if (!msg) {
    return;
  }
  // menu_num
  rosidl_runtime_c__int32__Sequence__fini(&msg->menu_num);
  // quantity_num
  rosidl_runtime_c__int32__Sequence__fini(&msg->quantity_num);
  // table_number
  // order_round
}

bool
ros_study_msgs__srv__OrderCustomer_Request__are_equal(const ros_study_msgs__srv__OrderCustomer_Request * lhs, const ros_study_msgs__srv__OrderCustomer_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // menu_num
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->menu_num), &(rhs->menu_num)))
  {
    return false;
  }
  // quantity_num
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->quantity_num), &(rhs->quantity_num)))
  {
    return false;
  }
  // table_number
  if (lhs->table_number != rhs->table_number) {
    return false;
  }
  // order_round
  if (lhs->order_round != rhs->order_round) {
    return false;
  }
  return true;
}

bool
ros_study_msgs__srv__OrderCustomer_Request__copy(
  const ros_study_msgs__srv__OrderCustomer_Request * input,
  ros_study_msgs__srv__OrderCustomer_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // menu_num
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->menu_num), &(output->menu_num)))
  {
    return false;
  }
  // quantity_num
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->quantity_num), &(output->quantity_num)))
  {
    return false;
  }
  // table_number
  output->table_number = input->table_number;
  // order_round
  output->order_round = input->order_round;
  return true;
}

ros_study_msgs__srv__OrderCustomer_Request *
ros_study_msgs__srv__OrderCustomer_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros_study_msgs__srv__OrderCustomer_Request * msg = (ros_study_msgs__srv__OrderCustomer_Request *)allocator.allocate(sizeof(ros_study_msgs__srv__OrderCustomer_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros_study_msgs__srv__OrderCustomer_Request));
  bool success = ros_study_msgs__srv__OrderCustomer_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ros_study_msgs__srv__OrderCustomer_Request__destroy(ros_study_msgs__srv__OrderCustomer_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ros_study_msgs__srv__OrderCustomer_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ros_study_msgs__srv__OrderCustomer_Request__Sequence__init(ros_study_msgs__srv__OrderCustomer_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros_study_msgs__srv__OrderCustomer_Request * data = NULL;

  if (size) {
    data = (ros_study_msgs__srv__OrderCustomer_Request *)allocator.zero_allocate(size, sizeof(ros_study_msgs__srv__OrderCustomer_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros_study_msgs__srv__OrderCustomer_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros_study_msgs__srv__OrderCustomer_Request__fini(&data[i - 1]);
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
ros_study_msgs__srv__OrderCustomer_Request__Sequence__fini(ros_study_msgs__srv__OrderCustomer_Request__Sequence * array)
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
      ros_study_msgs__srv__OrderCustomer_Request__fini(&array->data[i]);
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

ros_study_msgs__srv__OrderCustomer_Request__Sequence *
ros_study_msgs__srv__OrderCustomer_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros_study_msgs__srv__OrderCustomer_Request__Sequence * array = (ros_study_msgs__srv__OrderCustomer_Request__Sequence *)allocator.allocate(sizeof(ros_study_msgs__srv__OrderCustomer_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ros_study_msgs__srv__OrderCustomer_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ros_study_msgs__srv__OrderCustomer_Request__Sequence__destroy(ros_study_msgs__srv__OrderCustomer_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ros_study_msgs__srv__OrderCustomer_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ros_study_msgs__srv__OrderCustomer_Request__Sequence__are_equal(const ros_study_msgs__srv__OrderCustomer_Request__Sequence * lhs, const ros_study_msgs__srv__OrderCustomer_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros_study_msgs__srv__OrderCustomer_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros_study_msgs__srv__OrderCustomer_Request__Sequence__copy(
  const ros_study_msgs__srv__OrderCustomer_Request__Sequence * input,
  ros_study_msgs__srv__OrderCustomer_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros_study_msgs__srv__OrderCustomer_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ros_study_msgs__srv__OrderCustomer_Request * data =
      (ros_study_msgs__srv__OrderCustomer_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros_study_msgs__srv__OrderCustomer_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ros_study_msgs__srv__OrderCustomer_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ros_study_msgs__srv__OrderCustomer_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
ros_study_msgs__srv__OrderCustomer_Response__init(ros_study_msgs__srv__OrderCustomer_Response * msg)
{
  if (!msg) {
    return false;
  }
  // order_check
  return true;
}

void
ros_study_msgs__srv__OrderCustomer_Response__fini(ros_study_msgs__srv__OrderCustomer_Response * msg)
{
  if (!msg) {
    return;
  }
  // order_check
}

bool
ros_study_msgs__srv__OrderCustomer_Response__are_equal(const ros_study_msgs__srv__OrderCustomer_Response * lhs, const ros_study_msgs__srv__OrderCustomer_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // order_check
  if (lhs->order_check != rhs->order_check) {
    return false;
  }
  return true;
}

bool
ros_study_msgs__srv__OrderCustomer_Response__copy(
  const ros_study_msgs__srv__OrderCustomer_Response * input,
  ros_study_msgs__srv__OrderCustomer_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // order_check
  output->order_check = input->order_check;
  return true;
}

ros_study_msgs__srv__OrderCustomer_Response *
ros_study_msgs__srv__OrderCustomer_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros_study_msgs__srv__OrderCustomer_Response * msg = (ros_study_msgs__srv__OrderCustomer_Response *)allocator.allocate(sizeof(ros_study_msgs__srv__OrderCustomer_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros_study_msgs__srv__OrderCustomer_Response));
  bool success = ros_study_msgs__srv__OrderCustomer_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ros_study_msgs__srv__OrderCustomer_Response__destroy(ros_study_msgs__srv__OrderCustomer_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ros_study_msgs__srv__OrderCustomer_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ros_study_msgs__srv__OrderCustomer_Response__Sequence__init(ros_study_msgs__srv__OrderCustomer_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros_study_msgs__srv__OrderCustomer_Response * data = NULL;

  if (size) {
    data = (ros_study_msgs__srv__OrderCustomer_Response *)allocator.zero_allocate(size, sizeof(ros_study_msgs__srv__OrderCustomer_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros_study_msgs__srv__OrderCustomer_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros_study_msgs__srv__OrderCustomer_Response__fini(&data[i - 1]);
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
ros_study_msgs__srv__OrderCustomer_Response__Sequence__fini(ros_study_msgs__srv__OrderCustomer_Response__Sequence * array)
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
      ros_study_msgs__srv__OrderCustomer_Response__fini(&array->data[i]);
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

ros_study_msgs__srv__OrderCustomer_Response__Sequence *
ros_study_msgs__srv__OrderCustomer_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros_study_msgs__srv__OrderCustomer_Response__Sequence * array = (ros_study_msgs__srv__OrderCustomer_Response__Sequence *)allocator.allocate(sizeof(ros_study_msgs__srv__OrderCustomer_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ros_study_msgs__srv__OrderCustomer_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ros_study_msgs__srv__OrderCustomer_Response__Sequence__destroy(ros_study_msgs__srv__OrderCustomer_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ros_study_msgs__srv__OrderCustomer_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ros_study_msgs__srv__OrderCustomer_Response__Sequence__are_equal(const ros_study_msgs__srv__OrderCustomer_Response__Sequence * lhs, const ros_study_msgs__srv__OrderCustomer_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros_study_msgs__srv__OrderCustomer_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros_study_msgs__srv__OrderCustomer_Response__Sequence__copy(
  const ros_study_msgs__srv__OrderCustomer_Response__Sequence * input,
  ros_study_msgs__srv__OrderCustomer_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros_study_msgs__srv__OrderCustomer_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ros_study_msgs__srv__OrderCustomer_Response * data =
      (ros_study_msgs__srv__OrderCustomer_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros_study_msgs__srv__OrderCustomer_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ros_study_msgs__srv__OrderCustomer_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ros_study_msgs__srv__OrderCustomer_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
