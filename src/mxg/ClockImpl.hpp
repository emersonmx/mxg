#ifndef MXG_CLOCKIMPL_HPP_
#define MXG_CLOCKIMPL_HPP_

#include <mxg/Time.hpp>

namespace mxg {
namespace priv {

class ClockImpl {
public:
    static Time getCurrentTime();
};

} /* namespace priv */
} /* namespace mxg */
#endif /* MXG_CLOCKIMPL_HPP_ */
