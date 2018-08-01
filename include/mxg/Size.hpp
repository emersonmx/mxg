#ifndef MXG_SIZE_HPP_
#define MXG_SIZE_HPP_

#include <cstdint>

#include <mxg/Vector2.hpp>

namespace mxg {

class Size {
public:
    Size() = default;
    Size(const uint32_t aWidth, const uint32_t aHeight);

    Vector2 toVector2() const;
    operator Vector2() const { return toVector2(); }

    uint32_t width;
    uint32_t height;
};

bool operator == (const Size& left, const Size& right);
bool operator != (const Size& left, const Size& right);

} /* namespace mxg */
#endif /* MXG_SIZE_HPP_ */
