#pragma once

namespace mrl
{
  enum class BrakeMode
  {
    COAST,
    BRAKE,
    HOLD
  };

  class Motor
  {
  public:
    virtual ~Motor() = default;
    virtual void setVoltage(float volts) = 0;
    virtual float getPosition() const = 0;
    virtual float getVelocity() const = 0;
    virtual void setBrake(BrakeMode mode) = 0;
  };
}