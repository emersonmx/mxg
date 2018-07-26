#include <mxg/Size.hpp>

namespace mxg {

Size::Size(uint32_t aWidth, uint32_t aHeight) {
    width = aWidth;
    height = aHeight;
}

Vector2 Size::toVector2() const {
    return Vector2{
        static_cast<float>(width),
        static_cast<float>(height)
    };
}

bool operator == (const Size& left, const Size& right) {
    return left.width == right.width && left.height == right.height;
}

bool operator != (const Size& left, const Size& right) {
    return left.width != right.width || left.height != right.height;
}

} /* namespace mxg */
