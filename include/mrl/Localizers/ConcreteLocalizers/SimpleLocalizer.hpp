#pragma once
#include "mrl/Localizers/Localizer.hpp"
#include "mrl/Localizers/Odometry/TwoAxisTwoWheelOdometry.hpp"
namespace mrl
{
  class SimpleLocalizer : public Localizer
  {
  private:
    OdometryModel &odometry_;
    Pose pose_;

  public:
    SimpleLocalizer(OdometryModel &odometry);
    Pose getPose() const override;
    void setPose(const Pose &pose) override;
    void reset() override;
    void update() override;
  };

}