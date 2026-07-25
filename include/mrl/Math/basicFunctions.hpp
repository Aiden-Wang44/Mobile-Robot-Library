#pragma once
inline float sign(float input)
{
  return input < 0.0f ? -1.0f : 1.0f;
}

inline float clamp(float value, float maximum, float minimum)
{
  if (value > maximum)
  {
    return maximum;
  }
  else if (value < minimum)
  {
    return minimum;
  }
  else
  {
    return value;
  }
}