#pragma once
#include "mrl/Utilities/Geometry/Vector3.hpp"
namespace mrl
{
  class IMU
  {
  public:
    virtual ~IMU() = default;
    virtual float getHeading() const = 0;
    virtual float getRotation() const = 0;
    virtual void setHeading(float heading) = 0;
    virtual void setRotation(float rotation) = 0;
    virtual float getAngularVelocity() const = 0;
    virtual void calibrate() = 0;
    virtual void resetHeading() = 0;
    virtual bool isCalibrating() = 0;
    virtual Vector3 getAcceleration() const = 0;
  };
}