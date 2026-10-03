#pragma once
//Arbitrary brake modes that can be implemented in any way or ignored
//Coast corresponds to no electronic or physical braking
//Brake corresponds to electronic braking
//Hold corresponds to braking intended to hold motor position
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
    virtual void setVelocity(float velocity) = 0;
    virtual float getPosition() const = 0;
    virtual float getVelocity() const = 0;
    virtual void setBrake(BrakeMode mode) = 0;
  };
}