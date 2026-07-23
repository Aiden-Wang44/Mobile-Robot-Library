#pragma once
namespace mrl
{
  struct Pose
  {
    float x = 0.0f;
    float y = 0.0f;
    float heading = 0.0f;
    Pose() : x(0.0f), y(0.0f), heading(0.0f) {};
    Pose(float x_, float y_, float heading_) : x(x_), y(y_), heading(heading_) {}
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
    DeltaPose(float dx_, float dy_, float dtheta_) : dx(dx_), dy(dy_), dtheta(dtheta_) {}
  };

}