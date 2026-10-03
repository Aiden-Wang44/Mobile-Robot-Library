#include "mrl/Controllers/PID/PID.hpp"

namespace mrl
{
  float linearError(float target, float input)
  {
    return target - input;
  }
  PID::PID(const PIDConfig &config, Timer &convergeTimer, Timer &stuckTimer, ErrorFunction function = linearError) : config_(config), convergeTimer_(convergeTimer), stuckTimer_(stuckTimer), errorFunction_(function)
  {
    computeMaxIntegral();
  }
  void PID::setConfig(const PIDConfig &config)
  {
    config_ = config;
    computeMaxIntegral();
  }
  void PID::setTarget(float target)
  {
    reset();
    target_ = target;
  }
  void PID::reset()
  {
    firstIter_ = true;
    output_ = 0.0f;
    errorCurr_ = 0.0f;
    errorDer_ = 0.0f;
    errorInt_ = 0.0f;
    errorPrev_ = 0.0f;
    P_ = 0.0f;
    D_ = 0.0f;
    I_ = 0.0f;
    settled_ = false;
    convergeTimer_.reset();
    stuckTimer_.reset();
  }
  float PID::getOutput() const
  {
    return output_;
  }
  float PID::getI() const
  {
    return I_;
  }
  float PID::getD() const
  {
    return D_;
  }
  float PID::getError() const
  {
    return errorCurr_;
  }
  void PID::computeMaxIntegral()
  {
    if (config_.ki == 0.0f)
    {
      maxIntegral_ = 0.0f;
    }
    else
    {
      maxIntegral_ = config_.IMax / config_.ki;
    }
  }
  void PID::update(float input)
  {
    errorCurr_ = errorFunction_(target_, input);

    P_ = config_.kp * errorCurr_;
//checks for first iteration to prevent erroneus initial valus
    if (firstIter_)
    {
      firstIter_ = false;
      errorPrev_ = errorCurr_;
      errorInt_ = 0.0f;
    }
    errorDer_ = errorCurr_ - errorPrev_;

    if (std::fabs(errorCurr_) >= config_.IRange)
    {
      errorInt_ = 0.0f;
    }
    else
    {
      errorInt_ += errorCurr_;

      errorInt_ = mrl::clamp(errorInt_, -maxIntegral_, maxIntegral_);
    }
//Prevents integral use when the current value passes the target range
    if ((mrl::sign(errorInt_) != mrl::sign(errorCurr_)) || (std::fabs(errorCurr_) <= config_.errorTolerance))
    {
      errorInt_ = 0.0f;
    }
    I_ = errorInt_ * config_.ki;
    D_ = errorDer_ * config_.kd;
    if (stuckTimer_.getTime() >= config_.stuckTime && std::fabs(errorCurr_ - errorPrev_) < config_.jammedThreshold)
    {
      settled_ = true;
    }
//Derivative based settling to ensure a near stable exit
    if (std::fabs(errorCurr_) <= config_.errorTolerance && std::fabs(D_) <= config_.DTolerance)
    {
      if (convergeTimer_.getTime() >= config_.settleTime)
      {
        settled_ = true;
      }
    }
    else
    {
      convergeTimer_.reset();
    }
    output_ = P_ + I_ + D_;
    errorPrev_ = errorCurr_;
  }
  bool PID::targetArrived() const
  {
    return settled_;
  }
  void PID::setIDLimiters(float IMax_, float IRange_, float DMax_, float DRange_)
  {
    config_.IMax = IMax_;
    config_.IRange = IRange_;
    config_.DMax = DMax_;
    config_.DRange = DRange_;
  }
  void PID::setTolerance(float errorTolerance_, float DTolerance_)
  {
    config_.errorTolerance = errorTolerance_;
    config_.DTolerance = DTolerance_;
  }
  void PID::setTimeConfig(float settleTime_, float stuckTime_, float jammedThreshold_)
  {
    config_.settleTime = settleTime_;
    config_.stuckTime = stuckTime_;
    config_.jammedThreshold = jammedThreshold_;
  }

}