#ifndef MXG_SDL_TEXTURE_HPP_
#define MXG_SDL_TEXTURE_HPP_

#include <SDL_render.h>

#include <mxg/Size.hpp>

namespace mxg {
namespace sdl {

class Texture {
public:
    Texture() = default;
    Texture(SDL_Texture* texture, const Size& size);

    void destroy();

    Size getSize() const { return size_; }

    SDL_Texture* get() const { return texture_; }
    operator SDL_Texture*() const { return texture_; }

private:
    SDL_Texture* texture_{};
    Size size_{};
};

} /* namespace sdl */
} /* namespace mxg */
#endif /* MXG_SDL_TEXTURE_HPP_ */
