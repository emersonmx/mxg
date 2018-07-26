#ifndef MXG_CLOCK_HPP_
#define MXG_CLOCK_HPP_

#include <mxg/Time.hpp>

namespace mxg {

class Clock {
public:
    Clock();

    Time getElapsedTime() const;

    Time restart();

private:
    Time startTime_;
};

} /* namespace mxg */
#endif /* MXG_CLOCK_HPP_ */
