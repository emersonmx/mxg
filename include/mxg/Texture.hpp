#ifndef MXG_TEXTURE_HPP_
#define MXG_TEXTURE_HPP_

#include <mxg/Size.hpp>

namespace mxg {

class Texture {
public:
    virtual void create(const Size& size) = 0;
    virtual void destroy() = 0;

    virtual Size getSize() const = 0;
};

} /* namespace mxg */
#endif /* MXG_TEXTURE_HPP_ */
