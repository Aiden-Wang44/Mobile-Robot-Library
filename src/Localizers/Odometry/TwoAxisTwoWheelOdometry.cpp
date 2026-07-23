#include "mrl/Localizers/Odometry/TwoAxisTwoWheelOdometry.hpp"
namespace mrl
{
  TwoAxisTwoWheelOdometry::TwoAxisTwoWheelOdometry(TrackerWheel &horizontalTrackerWheel, TrackerWheel &verticalTrackerWheel, IMU &imu, OdomGeometry geometry) : horizontalTrackerWheel_(horizontalTrackerWheel), verticalTrackerWheel_(verticalTrackerWheel), imu_(imu), geometry_(geometry)
  {
    previousHorizontalTrackerPositionValue_ = horizontalTrackerWheel_.getDistance();

    previousVerticalTrackerPositionValue_ = verticalTrackerWheel_.getDistance();
    previousIMUHeading_ = imu_.getHeading();
  }

  DeltaPose TwoAxisTwoWheelOdometry::update()
  {
    const float horizontalDistance = horizontalTrackerWheel_.getDistance();
    const float verticalDistance = verticalTrackerWheel_.getDistance();
    const float imuHeading = imu_.getHeading();
    const float dH = horizontalDistance - previousHorizontalTrackerPositionValue_;
    const float dV = verticalDistance - previousVerticalTrackerPositionValue_;
    const float dTheta = imuHeading - previousIMUHeading_;
    DeltaPose deltaPose = DeltaPose(
        dH - geometry_.horizontalOffset * dTheta,
        dV - geometry_.verticalOffset * dTheta,
        dTheta);
    previousHorizontalTrackerPositionValue_ = horizontalDistance;
    previousVerticalTrackerPositionValue_ = verticalDistance;
    previousIMUHeading_ = imuHeading;
    return deltaPose;
  }
}