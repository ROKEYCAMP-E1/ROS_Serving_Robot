// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ros_study_msgs:msg/MoveRobot.idl
// generated code does not contain a copyright notice

#ifndef ROS_STUDY_MSGS__MSG__DETAIL__MOVE_ROBOT__BUILDER_HPP_
#define ROS_STUDY_MSGS__MSG__DETAIL__MOVE_ROBOT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ros_study_msgs/msg/detail/move_robot__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ros_study_msgs
{

namespace msg
{

namespace builder
{

class Init_MoveRobot_topic_move_robot
{
public:
  Init_MoveRobot_topic_move_robot()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::ros_study_msgs::msg::MoveRobot topic_move_robot(::ros_study_msgs::msg::MoveRobot::_topic_move_robot_type arg)
  {
    msg_.topic_move_robot = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ros_study_msgs::msg::MoveRobot msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ros_study_msgs::msg::MoveRobot>()
{
  return ros_study_msgs::msg::builder::Init_MoveRobot_topic_move_robot();
}

}  // namespace ros_study_msgs

#endif  // ROS_STUDY_MSGS__MSG__DETAIL__MOVE_ROBOT__BUILDER_HPP_
