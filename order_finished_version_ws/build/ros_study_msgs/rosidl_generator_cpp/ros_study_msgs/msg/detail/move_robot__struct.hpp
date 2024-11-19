// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros_study_msgs:msg/MoveRobot.idl
// generated code does not contain a copyright notice

#ifndef ROS_STUDY_MSGS__MSG__DETAIL__MOVE_ROBOT__STRUCT_HPP_
#define ROS_STUDY_MSGS__MSG__DETAIL__MOVE_ROBOT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros_study_msgs__msg__MoveRobot __attribute__((deprecated))
#else
# define DEPRECATED__ros_study_msgs__msg__MoveRobot __declspec(deprecated)
#endif

namespace ros_study_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MoveRobot_
{
  using Type = MoveRobot_<ContainerAllocator>;

  explicit MoveRobot_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->topic_move_robot = 0;
    }
  }

  explicit MoveRobot_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->topic_move_robot = 0;
    }
  }

  // field types and members
  using _topic_move_robot_type =
    int8_t;
  _topic_move_robot_type topic_move_robot;

  // setters for named parameter idiom
  Type & set__topic_move_robot(
    const int8_t & _arg)
  {
    this->topic_move_robot = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros_study_msgs::msg::MoveRobot_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros_study_msgs::msg::MoveRobot_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros_study_msgs::msg::MoveRobot_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros_study_msgs::msg::MoveRobot_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros_study_msgs::msg::MoveRobot_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros_study_msgs::msg::MoveRobot_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros_study_msgs::msg::MoveRobot_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros_study_msgs::msg::MoveRobot_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros_study_msgs::msg::MoveRobot_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros_study_msgs::msg::MoveRobot_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros_study_msgs__msg__MoveRobot
    std::shared_ptr<ros_study_msgs::msg::MoveRobot_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros_study_msgs__msg__MoveRobot
    std::shared_ptr<ros_study_msgs::msg::MoveRobot_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MoveRobot_ & other) const
  {
    if (this->topic_move_robot != other.topic_move_robot) {
      return false;
    }
    return true;
  }
  bool operator!=(const MoveRobot_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MoveRobot_

// alias to use template instance with default allocator
using MoveRobot =
  ros_study_msgs::msg::MoveRobot_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ros_study_msgs

#endif  // ROS_STUDY_MSGS__MSG__DETAIL__MOVE_ROBOT__STRUCT_HPP_
