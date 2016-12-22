#ifndef MXG_MAPS_OBJECTS_ELLIPSE_HPP_
#define MXG_MAPS_OBJECTS_ELLIPSE_HPP_

#include "mxg/maps/Object.hpp"
#include "mxg/math/Ellipse.hpp"

namespace mxg {
namespace maps {
namespace objects {

template<typename T>
struct Ellipse : mxg::maps::Object {
    mxg::math::Ellipse<T> ellipse{};
};

} /* namespace objects */
} /* namespace maps */
} /* namespace mxg */
#endif /* MXG_MAPS_OBJECTS_ELLIPSE_HPP_ */
