#ifndef MXG_MAPS_OBJECT_HPP_
#define MXG_MAPS_OBJECT_HPP_

#include "mxg/graphics/Color.hpp"
#include "mxg/maps/Properties.hpp"

namespace mxg {
namespace maps {

struct Object {
    std::string name = "";
    float opacity = 1.0f;
    bool visible = true;
    Properties properties{};
    mxg::graphics::Color color = mxg::graphics::Color::White;
};

} /* namespace maps */
} /* namespace mxg */
#endif /* MXG_MAPS_OBJECT_HPP_ */
