#ifndef MXG_MAPS_OBJECT_HPP_
#define MXG_MAPS_OBJECT_HPP_

#include "mxg/maps/Properties.hpp"

namespace mxg {
namespace maps {

template<class ColorType>
struct Object {
    std::string name = "";
    float opacity = 1.0f;
    bool visible = true;
    Properties properties{};
    ColorType color{};
};

} /* namespace maps */
} /* namespace mxg */
#endif /* MXG_MAPS_OBJECT_HPP_ */
