#ifndef MXG_SDL_TRANSFORM_HPP_
#define MXG_SDL_TRANSFORM_HPP_

#include <SDL_render.h>

#include <mxg/Vector2.hpp>
#include <mxg/Size.hpp>

namespace mxg {
namespace sdl {

struct Transform {
    Vector2 position{};
    Vector2 scale{1, 1};
    double angle{};
    Vector2 origin{};
    SDL_RendererFlip flip{SDL_FLIP_NONE};
};

} /* namespace sdl */
} /* namespace mxg */
#endif /* MXG_SDL_TRANSFORM_HPP_ */
