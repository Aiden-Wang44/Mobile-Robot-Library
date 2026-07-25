#pragma once
#include "mrl/Controllers/Controller.hpp"
#include "mrl/Math/basicFunctions.hpp"
#include "mrl/Utilities/Timer/Timer.hpp"
#include <cmath>
#include <functional>
namespace mrl
{
  using ErrorFunction = float (*)(float, float);
  struct PIDConfig
  {
    float kp = 0.0f;
    float ki = 0.0f;
    float kd = 0.0f;

    float IMax = 0.0f;
    float IRange = 0.0f;
    float DRange = 0.0f;
    float DMax = 0.0f;

    float errorTolerance;
    float DTolerance;

    float settleTime;
    float stuckTime;
    float jammedThreshold;
    PIDConfig() = default;
    PIDConfig(float kp_, float ki_, float kd_) : kp(kp_), ki(ki_), kd(kd_)
    {
    }
  };

  class PID : public Controller
  {
  private:
    ErrorFunction errorFunction_;

    float errorCurr_ = 0.0f, errorPrev_ = 0.0f, errorDer_ = 0.0f, errorInt_ = 0.0f;
    float P_ = 0.0f, I_ = 0.0f, D_ = 0.0f;
    bool firstIter_ = true;
    PIDConfig config_;
    float target_ = 0.0f;
    float output_ = 0.0f;
    float maxIntegral_ = 0.0f;
    bool settled_ = false;

    Timer &convergeTimer_;
    Timer &stuckTimer_;

  public:
    PID(const PIDConfig &config, Timer &convergeTimer, Timer &stuckTimer, ErrorFunction errorFunction_);

    void setConfig(const PIDConfig &config);
    void setTarget(float target) override;
    void reset() override;
    void update(float input) override;
    float getOutput() const override;
    float getI() const;
    float getD() const;
    float getError() const override;
    bool targetArrived() const override;
    void computeMaxIntegral();
    void setIDLimiters(float IMax_, float IRange, float DMax_, float DRange_);
    void setTolerance(float errorTolerance_, float DTolerance_);
    void setTimeConfig(float settleTime_, float stuckTime_, float jammedThreshold_);
  };
}