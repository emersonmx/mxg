#ifndef MXG_MAPS_OBJECTS_CIRCLE_HPP_
#define MXG_MAPS_OBJECTS_CIRCLE_HPP_

#include "mxg/maps/Object.hpp"

namespace mxg {
namespace maps {
namespace objects {

template<class CircleType>
struct Circle : mxg::maps::Object {
    CircleType circle{};
};

} /* namespace objects */
} /* namespace maps */
} /* namespace mxg */
#endif /* MXG_MAPS_OBJECTS_CIRCLE_HPP_ */
