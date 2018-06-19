#ifndef MXG_SDL_RENDERER_HPP_
#define MXG_SDL_RENDERER_HPP_

#include <SDL_render.h>

#include <mxg/Color.hpp>
#include <mxg/sdl/Texture.hpp>
#include <mxg/sdl/Transform.hpp>

namespace mxg {
namespace sdl {

class Renderer {
public:
    Renderer() = default;
    Renderer(SDL_Window* window);

    void create(SDL_Window* window);
    void destroy();

    Color getClearColor() const;
    void setClearColor(const Color& color);

    void clear();
    void clear(const Color& color);
    void render(const Texture& texture, const Vector2& position);
    void render(const Texture& texture, const Transform& transform);
    void present();

    SDL_Renderer* get() const { return renderer_; }
    operator SDL_Renderer*() const { return renderer_; }

private:
    SDL_Renderer* renderer_{};
};

} /* namespace sdl */
} /* namespace mxg */
#endif /* MXG_SDL_RENDERER_HPP_ */
