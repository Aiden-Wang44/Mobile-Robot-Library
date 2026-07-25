#pragma once
namespace mrl
{
  inline float sign(float input)
  {
    return input < 0.0f ? -1.0f : 1.0f;
  }

  inline float clamp(float value, float maximum, float minimum)
  {
    if (std::fabs(value) > maximum)
    {
      return maximum * sign(value);
    }
    else if (std::fabs(value) < minimum)
    {
      return minimum * sign(value);
    }
    else
    {
      return value;
    }
  }
}