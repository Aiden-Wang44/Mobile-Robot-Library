#pragma once
#include "mrl/Sensors/Rotation.hpp"
namespace mrl
{
  class TrackerWheel
  {
  private:
    Rotation &rotation_;
    bool reversed_ = false;
    float wheelDiameter_;
    float wheelCircumference_;
    float gearRatio_;
    float distanceOffset_ = 0.0f;

  public:
    explicit TrackerWheel(Rotation &rotation, float wheelDiameter, float gearRatio);
    float getDistance() const;
    void setDistanceOffset(float);
    void resetDistanceOffset();
    void setReverse(bool);
    float getVelocity() const;
  };
}