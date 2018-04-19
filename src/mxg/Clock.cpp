#include <mxg/Clock.hpp>
#include <mxg/ClockImpl.hpp>

namespace mxg {

Clock::Clock() : startTime_(priv::ClockImpl::getCurrentTime()) {}

Time Clock::getElapsedTime() const {
    return priv::ClockImpl::getCurrentTime();
}

Time Clock::restart() {
    Time now = priv::ClockImpl::getCurrentTime();
    Time elapsed = now - startTime_;
    startTime_ = now;
    return elapsed;
}

} /* namespace mxg */
