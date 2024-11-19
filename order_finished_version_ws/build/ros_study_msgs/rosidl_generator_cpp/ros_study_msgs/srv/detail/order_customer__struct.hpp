// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros_study_msgs:srv/OrderCustomer.idl
// generated code does not contain a copyright notice

#ifndef ROS_STUDY_MSGS__SRV__DETAIL__ORDER_CUSTOMER__STRUCT_HPP_
#define ROS_STUDY_MSGS__SRV__DETAIL__ORDER_CUSTOMER__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros_study_msgs__srv__OrderCustomer_Request __attribute__((deprecated))
#else
# define DEPRECATED__ros_study_msgs__srv__OrderCustomer_Request __declspec(deprecated)
#endif

namespace ros_study_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct OrderCustomer_Request_
{
  using Type = OrderCustomer_Request_<ContainerAllocator>;

  explicit OrderCustomer_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->table_number = 0;
      this->order_round = 0;
    }
  }

  explicit OrderCustomer_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->table_number = 0;
      this->order_round = 0;
    }
  }

  // field types and members
  using _menu_num_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _menu_num_type menu_num;
  using _quantity_num_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _quantity_num_type quantity_num;
  using _table_number_type =
    int8_t;
  _table_number_type table_number;
  using _order_round_type =
    int8_t;
  _order_round_type order_round;

  // setters for named parameter idiom
  Type & set__menu_num(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->menu_num = _arg;
    return *this;
  }
  Type & set__quantity_num(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->quantity_num = _arg;
    return *this;
  }
  Type & set__table_number(
    const int8_t & _arg)
  {
    this->table_number = _arg;
    return *this;
  }
  Type & set__order_round(
    const int8_t & _arg)
  {
    this->order_round = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros_study_msgs::srv::OrderCustomer_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros_study_msgs::srv::OrderCustomer_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros_study_msgs::srv::OrderCustomer_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros_study_msgs::srv::OrderCustomer_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros_study_msgs::srv::OrderCustomer_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros_study_msgs::srv::OrderCustomer_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros_study_msgs::srv::OrderCustomer_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros_study_msgs::srv::OrderCustomer_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros_study_msgs::srv::OrderCustomer_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros_study_msgs::srv::OrderCustomer_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros_study_msgs__srv__OrderCustomer_Request
    std::shared_ptr<ros_study_msgs::srv::OrderCustomer_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros_study_msgs__srv__OrderCustomer_Request
    std::shared_ptr<ros_study_msgs::srv::OrderCustomer_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OrderCustomer_Request_ & other) const
  {
    if (this->menu_num != other.menu_num) {
      return false;
    }
    if (this->quantity_num != other.quantity_num) {
      return false;
    }
    if (this->table_number != other.table_number) {
      return false;
    }
    if (this->order_round != other.order_round) {
      return false;
    }
    return true;
  }
  bool operator!=(const OrderCustomer_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OrderCustomer_Request_

// alias to use template instance with default allocator
using OrderCustomer_Request =
  ros_study_msgs::srv::OrderCustomer_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros_study_msgs


#ifndef _WIN32
# define DEPRECATED__ros_study_msgs__srv__OrderCustomer_Response __attribute__((deprecated))
#else
# define DEPRECATED__ros_study_msgs__srv__OrderCustomer_Response __declspec(deprecated)
#endif

namespace ros_study_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct OrderCustomer_Response_
{
  using Type = OrderCustomer_Response_<ContainerAllocator>;

  explicit OrderCustomer_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->order_check = 0;
    }
  }

  explicit OrderCustomer_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->order_check = 0;
    }
  }

  // field types and members
  using _order_check_type =
    int8_t;
  _order_check_type order_check;

  // setters for named parameter idiom
  Type & set__order_check(
    const int8_t & _arg)
  {
    this->order_check = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros_study_msgs::srv::OrderCustomer_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros_study_msgs::srv::OrderCustomer_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros_study_msgs::srv::OrderCustomer_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros_study_msgs::srv::OrderCustomer_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros_study_msgs::srv::OrderCustomer_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros_study_msgs::srv::OrderCustomer_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros_study_msgs::srv::OrderCustomer_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros_study_msgs::srv::OrderCustomer_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros_study_msgs::srv::OrderCustomer_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros_study_msgs::srv::OrderCustomer_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros_study_msgs__srv__OrderCustomer_Response
    std::shared_ptr<ros_study_msgs::srv::OrderCustomer_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros_study_msgs__srv__OrderCustomer_Response
    std::shared_ptr<ros_study_msgs::srv::OrderCustomer_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OrderCustomer_Response_ & other) const
  {
    if (this->order_check != other.order_check) {
      return false;
    }
    return true;
  }
  bool operator!=(const OrderCustomer_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OrderCustomer_Response_

// alias to use template instance with default allocator
using OrderCustomer_Response =
  ros_study_msgs::srv::OrderCustomer_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros_study_msgs

namespace ros_study_msgs
{

namespace srv
{

struct OrderCustomer
{
  using Request = ros_study_msgs::srv::OrderCustomer_Request;
  using Response = ros_study_msgs::srv::OrderCustomer_Response;
};

}  // namespace srv

}  // namespace ros_study_msgs

#endif  // ROS_STUDY_MSGS__SRV__DETAIL__ORDER_CUSTOMER__STRUCT_HPP_
