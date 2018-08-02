#ifndef MXG_SDL2_RENDERER_HPP_
#define MXG_SDL2_RENDERER_HPP_

#include <memory>

#include <SDL2/SDL_render.h>

#include <mxg/Vector2.hpp>
#include <mxg/Color.hpp>
#include <mxg/sdl2/Texture.hpp>
#include <mxg/sdl2/Window.hpp>

namespace mxg {
namespace sdl2 {

struct SDLRendererDeleter {
    void operator()(SDL_Renderer* renderer) {
        SDL_DestroyRenderer(renderer);
    }
};

using SDLRendererPtr = std::unique_ptr<SDL_Renderer, SDLRendererDeleter>;

class Renderer {
public:
    Renderer(const Window& window);
    Renderer(SDL_Window* window);
    ~Renderer();

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;

    Color getClearColor() const;
    void setClearColor(const Color& color);
    SDL_Renderer* getContents() const;

    void create();
    void destroy();

    void clear();
    void clear(const Color& color);
    void render(const Texture& texture, const Vector2& position);
    void render(const Texture& texture,
                const Vector2& position,
                const float angle,
                const Vector2& scale,
                const Vector2& center);
    void present();

private:
    SDL_Window* window_{};
    SDLRendererPtr renderer_{};
};

} /* namespace sdl2 */
} /* namespace mxg */
#endif /* MXG_SDL2_RENDERER_HPP_ */
