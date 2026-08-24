#include "mrl/Core/Chassis/TankDrive.hpp"
namespace mrl
{
  TankDrive::TankDrive(MotorGroup &left, MotorGroup &right, float wheelRadius) : left_(left), right_(right), wheelRadius_(wheelRadius) {}
  void TankDrive::drive(float forward, float /*lateral*/, float angular)
  {
    left_.setVoltage(forward - angular);
    right_.setVoltage(forward + angular);
  }
  void TankDrive::driveVelocity(float forwardVelocity, float /*lateralVelocity*/, float angularVelocity)
  {
    left_.setVelocity(forwardVelocity - angularVelocity);
    right_.setVelocity(forwardVelocity + angularVelocity);
  }
  float TankDrive::getWheelRadius() const
  {
    return wheelRadius_;
  }
}