#include "ClockImpl.hpp"

#include <chrono>

namespace mxg {
namespace priv {

Time ClockImpl::getCurrentTime() {
    auto now = std::chrono::high_resolution_clock::now();
    auto duration = now.time_since_epoch();
    int64_t mcs = std::chrono::duration_cast<std::chrono::microseconds>(duration).count();
    return microseconds(mcs);
}

} /* namespace priv */
} /* namespace mxg */
