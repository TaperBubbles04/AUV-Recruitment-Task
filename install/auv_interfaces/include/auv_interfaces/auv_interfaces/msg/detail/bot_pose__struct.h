// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auv_interfaces:msg/BotPose.idl
// generated code does not contain a copyright notice

#ifndef AUV_INTERFACES__MSG__DETAIL__BOT_POSE__STRUCT_H_
#define AUV_INTERFACES__MSG__DETAIL__BOT_POSE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'facing_direction'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/BotPose in the package auv_interfaces.
typedef struct auv_interfaces__msg__BotPose
{
  float x;
  float y;
  rosidl_runtime_c__String facing_direction;
} auv_interfaces__msg__BotPose;

// Struct for a sequence of auv_interfaces__msg__BotPose.
typedef struct auv_interfaces__msg__BotPose__Sequence
{
  auv_interfaces__msg__BotPose * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auv_interfaces__msg__BotPose__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUV_INTERFACES__MSG__DETAIL__BOT_POSE__STRUCT_H_
