#pragma once

namespace mrl
{
  class Motor
  {
  public:
    virtual ~Motor() = default;
    virtual void setVoltage(float volts) = 0;
    virtual float getPosition() const = 0;
    virtual float getVelocity() const = 0;
    virtual void setBrake() = 0;
  };
}