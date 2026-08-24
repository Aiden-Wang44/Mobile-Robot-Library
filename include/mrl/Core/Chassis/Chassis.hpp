#pragma once
namespace mrl
{
  class Chassis
  {
  public:
    virtual ~Chassis() = default;
    virtual void drive(float forward, float lateral, float angular) = 0;
    virtual void driveVelocity(float forwardVelocity, float lateralVelocity, float angularVelocity) = 0;
    virtual float getWheelRadius() const = 0;
  };

}