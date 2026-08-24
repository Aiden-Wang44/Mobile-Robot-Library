#pragma once
#include "mrl/Math/Constants.hpp"
#include <cmath>
namespace mrl
{
  inline float normalizeAngle(float angle)
  {
    angle = std::fmod(angle + PI, 2.0f * PI);
    if (angle < 0.0f)
    {
      angle += 2.0f * PI;
    }
    return angle - PI;
  }
  inline float sinc(float x)
  {
    if (std::fabs(x) < 0.001f)
    {
      return 1.0f;
    }

    return std::sin(x) / x;
  }
}