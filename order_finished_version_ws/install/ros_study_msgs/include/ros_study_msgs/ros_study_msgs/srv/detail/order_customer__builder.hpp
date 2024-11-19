// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros_study_msgs:srv/OrderCustomer.idl
// generated code does not contain a copyright notice

#ifndef ROS_STUDY_MSGS__SRV__DETAIL__ORDER_CUSTOMER__BUILDER_HPP_
#define ROS_STUDY_MSGS__SRV__DETAIL__ORDER_CUSTOMER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros_study_msgs/srv/detail/order_customer__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros_study_msgs
{

namespace srv
{

namespace builder
{

class Init_OrderCustomer_Request_order_round
{
public:
  explicit Init_OrderCustomer_Request_order_round(::ros_study_msgs::srv::OrderCustomer_Request & msg)
  : msg_(msg)
  {}
  ::ros_study_msgs::srv::OrderCustomer_Request order_round(::ros_study_msgs::srv::OrderCustomer_Request::_order_round_type arg)
  {
    msg_.order_round = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_study_msgs::srv::OrderCustomer_Request msg_;
};

class Init_OrderCustomer_Request_table_number
{
public:
  explicit Init_OrderCustomer_Request_table_number(::ros_study_msgs::srv::OrderCustomer_Request & msg)
  : msg_(msg)
  {}
  Init_OrderCustomer_Request_order_round table_number(::ros_study_msgs::srv::OrderCustomer_Request::_table_number_type arg)
  {
    msg_.table_number = std::move(arg);
    return Init_OrderCustomer_Request_order_round(msg_);
  }

private:
  ::ros_study_msgs::srv::OrderCustomer_Request msg_;
};

class Init_OrderCustomer_Request_quantity_num
{
public:
  explicit Init_OrderCustomer_Request_quantity_num(::ros_study_msgs::srv::OrderCustomer_Request & msg)
  : msg_(msg)
  {}
  Init_OrderCustomer_Request_table_number quantity_num(::ros_study_msgs::srv::OrderCustomer_Request::_quantity_num_type arg)
  {
    msg_.quantity_num = std::move(arg);
    return Init_OrderCustomer_Request_table_number(msg_);
  }

private:
  ::ros_study_msgs::srv::OrderCustomer_Request msg_;
};

class Init_OrderCustomer_Request_menu_num
{
public:
  Init_OrderCustomer_Request_menu_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_OrderCustomer_Request_quantity_num menu_num(::ros_study_msgs::srv::OrderCustomer_Request::_menu_num_type arg)
  {
    msg_.menu_num = std::move(arg);
    return Init_OrderCustomer_Request_quantity_num(msg_);
  }

private:
  ::ros_study_msgs::srv::OrderCustomer_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_study_msgs::srv::OrderCustomer_Request>()
{
  return ros_study_msgs::srv::builder::Init_OrderCustomer_Request_menu_num();
}

}  // namespace ros_study_msgs


namespace ros_study_msgs
{

namespace srv
{

namespace builder
{

class Init_OrderCustomer_Response_order_check
{
public:
  Init_OrderCustomer_Response_order_check()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros_study_msgs::srv::OrderCustomer_Response order_check(::ros_study_msgs::srv::OrderCustomer_Response::_order_check_type arg)
  {
    msg_.order_check = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_study_msgs::srv::OrderCustomer_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_study_msgs::srv::OrderCustomer_Response>()
{
  return ros_study_msgs::srv::builder::Init_OrderCustomer_Response_order_check();
}

}  // namespace ros_study_msgs

#endif  // ROS_STUDY_MSGS__SRV__DETAIL__ORDER_CUSTOMER__BUILDER_HPP_
