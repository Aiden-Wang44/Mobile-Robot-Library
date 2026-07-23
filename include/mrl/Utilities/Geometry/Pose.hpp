#pragma once
namespace mrl
{
  struct Pose
  {
    float x = 0.0f;
    float y = 0.0f;
    float heading = 0.0f;
  };
  struct Twist
  {
    float vx = 0.0f;
    float vy = 0.0f;
    float omega = 0.0f;
  };
  struct DeltaPose
  {
    float dx = 0.0f;
    float dy = 0.0f;
    float dtheta = 0.0f;
  };

}