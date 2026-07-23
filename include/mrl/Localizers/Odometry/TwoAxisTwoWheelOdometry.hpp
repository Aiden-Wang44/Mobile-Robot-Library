#pragma once
#include "mrl/Core/TrackerWheel.hpp"
#include "mrl/Utilities/Geometry/Pose.hpp"
#include "mrl/Sensors/IMU.hpp"
#include "mrl/Localizers/Odometry/OdometryModel.hpp"
namespace mrl
{
  struct OdomGeometry
  {
    float horizontalOffset;
    float verticalOffset;
    OdomGeometry() : horizontalOffset(0.0f), verticalOffset(0.0f) {}
    OdomGeometry(float horizontal, float vertical) : horizontalOffset(horizontal), verticalOffset(vertical) {}
  };
  class TwoAxisTwoWheelOdometry : public OdometryModel
  {
  private:
    TrackerWheel &horizontalTrackerWheel_;
    TrackerWheel &verticalTrackerWheel_;
    OdomGeometry geometry_;
    IMU &imu_;
    float previousHorizontalTrackerPositionValue_;
    float previousVerticalTrackerPositionValue_;
    float previousIMUHeading_;

  public:
    TwoAxisTwoWheelOdometry(TrackerWheel &horizontal, TrackerWheel &vertical, IMU &imu, OdomGeometry geometry);
    DeltaPose update() override;
  };

}