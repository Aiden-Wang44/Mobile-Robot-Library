#include "mrl/Core/Chassis/TankDrive.hpp"
namespace mrl
{
  TankDrive::TankDrive(MotorGroup &left, MotorGroup &right) : left_(left), right_(right) {}
  void TankDrive::drive(float forward, float /*lateral*/, float angular)
  {
    left_.setVoltage(forward - angular);
    right_.setVoltage(forward + angular);
  }
}