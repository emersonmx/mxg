#ifndef MXG_MAPS_OBJECTS_RECTANGLE_HPP_
#define MXG_MAPS_OBJECTS_RECTANGLE_HPP_

#include "mxg/maps/Object.hpp"
#include "mxg/math/Rectangle.hpp"

namespace mxg {
namespace maps {
namespace objects {

template<typename T>
struct Rectangle : mxg::maps::Object {
    mxg::math::Rectangle<T> rectangle{};
};

} /* namespace objects */
} /* namespace maps */
} /* namespace mxg */
#endif /* MXG_MAPS_OBJECTS_RECTANGLE_HPP_ */
