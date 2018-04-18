#include <mxg/Size.hpp>

namespace mxg {

Size::Size(uint32_t aWidth, uint32_t aHeight) {
    width = aWidth;
    height = aHeight;
}

bool operator == (const Size& left, const Size& right) {
    return left.width == right.width && left.height == right.height;
}

bool operator != (const Size& left, const Size& right) {
    return left.width != right.width || left.height != right.height;
}

} /* namespace mxg */
