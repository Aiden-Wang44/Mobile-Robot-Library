#pragma once
namespace mrl
{
  inline float sign(float input)
  {
    return input < 0.0f ? -1.0f : 1.0f;
  }
  inline float fabs(float input)
  {
    return input < 0.0f ? -1.0f * input : 1.0f * input;
  }

  inline float clamp(float value, float maximum, float minimum)
  {
    if (mrl::fabs(value) > maximum)
    {
      return maximum * sign(value);
    }
    else if (mrl::fabs(value) < minimum)
    {
      return minimum * sign(value);
    }
    else
    {
      return value;
    }
  }
}