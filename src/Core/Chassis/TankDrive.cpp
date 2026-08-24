#include "mrl/Core/Chassis/TankDrive.hpp"
#include "mrl/Math/Angles.hpp"
namespace mrl
{
  TankDrive::TankDrive(MotorGroup &left, MotorGroup &right, float wheelDiameter, float trackWidth) : left_(left), right_(right), wheelDiameter_(wheelDiameter), trackWidth_(trackWidth) {}
  void TankDrive::drive(float forward, float /*lateral*/, float angular)
  {
    left_.setVoltage(forward - angular);
    right_.setVoltage(forward + angular);
  }
  void TankDrive::driveVelocity(float forwardVelocity, float /*lateralVelocity*/, float angularVelocity)
  {
    left_.setVelocity((forwardVelocity - angularVelocity * trackWidth_ / 2.0f) / (wheelDiameter_ * PI));
    right_.setVelocity((forwardVelocity + angularVelocity * trackWidth_ / 2.0f) / (wheelDiameter_ * PI));
  }

}