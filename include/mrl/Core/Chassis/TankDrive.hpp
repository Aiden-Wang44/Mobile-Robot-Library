#pragma once
#include "mrl/Core/Chassis/Chassis.hpp"
#include "mrl/Core/MotorGroup.hpp"
//All math is unit agnostic at the library level
//Angles should be in radians with CCW being positive
//Coordinate convention is positive Y axis is 0 radians
namespace mrl
{
  class TankDrive : public Chassis
  {
  private:
    MotorGroup &left_;
    MotorGroup &right_;
    float wheelDiameter_ = 0.0f;
    float trackWidth_ = 0.0f;

  public:
    explicit TankDrive(MotorGroup &left, MotorGroup &right, float wheelDiameter, float trackWidth);
    void drive(float forward, float lateral, float angular) override;
    void driveVelocity(float forwardVelocity, float lateralVelocity, float angularVelocity) override;
    };

}