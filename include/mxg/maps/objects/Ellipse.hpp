#ifndef MXG_MAPS_OBJECTS_ELLIPSE_HPP_
#define MXG_MAPS_OBJECTS_ELLIPSE_HPP_

#include "mxg/maps/Object.hpp"

namespace mxg {
namespace maps {
namespace objects {

template<class ColorType, class EllipseType>
struct Ellipse : mxg::maps::Object<ColorType> {
    EllipseType ellipse{};
};

} /* namespace objects */
} /* namespace maps */
} /* namespace mxg */
#endif /* MXG_MAPS_OBJECTS_ELLIPSE_HPP_ */