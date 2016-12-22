#ifndef MXG_MAPS_OBJECTS_CIRCLE_HPP_
#define MXG_MAPS_OBJECTS_CIRCLE_HPP_

#include "mxg/maps/Object.hpp"
#include "mxg/math/Circle.hpp"

namespace mxg {
namespace maps {
namespace objects {

template<typename T>
struct Circle : mxg::maps::Object {
    mxg::math::Circle<T> circle{};
};

} /* namespace objects */
} /* namespace maps */
} /* namespace mxg */
#endif /* MXG_MAPS_OBJECTS_CIRCLE_HPP_ */
