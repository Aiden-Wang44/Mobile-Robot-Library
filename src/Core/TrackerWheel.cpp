
#include "mrl/Core/TrackerWheel.hpp"
#include "mrl/Math/Constants.hpp"
namespace mrl
{
  TrackerWheel::TrackerWheel(Rotation &rotation, float wheelDiameter, float gearRatio) : rotation_(rotation), wheelDiameter_(wheelDiameter), gearRatio_(gearRatio), wheelCircumference_(wheelDiameter * PI)
  {
  }
  float TrackerWheel::getDistance() const
  {
    float temp = rotation_.getPosition() * gearRatio_ * wheelCircumference_ / 360.0f;
    return (reversed_ ? -1.0f * temp : temp) + distanceOffset_;
  }
  void TrackerWheel::setDistanceOffset(float distanceOffset)
  {
    distanceOffset_ = distanceOffset;
  }
  void TrackerWheel::resetDistanceOffset()
  {
    distanceOffset_ = 0.0f;
  }
  void TrackerWheel::setReverse(bool reversed)
  {
    reversed_ = reversed;
  }
  float TrackerWheel::getVelocity() const
  {
    float temp = rotation_.getVelocity() * gearRatio_ * wheelCircumference_ / 360.0f;
    return reversed_ ? -1.0f * temp : temp;
  }

}