#include <mxg/sdl/Renderer.hpp>

#include <cassert>
#include <sstream>

#include <mxg/Exception.hpp>

namespace mxg {
namespace sdl {

Renderer::Renderer(SDL_Window* window) {
    create(window);
}

void Renderer::destroy() {
    SDL_DestroyRenderer(renderer_);
    renderer_ = nullptr;
}

void Renderer::create(SDL_Window* window) {
    renderer_ = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer_ == nullptr) {
        std::ostringstream message{};
        message << "Couldn't create renderer\n";
        message << "    Error: " << SDL_GetError() << '\n';
        throw Exception(message.str());
    }

    setClearColor({});
}

Color Renderer::getClearColor() const {
    assert(renderer_ != nullptr);

    Color color;
    SDL_GetRenderDrawColor(renderer_, &color.red, &color.green, &color.blue, &color.alpha);
    return color;
}

void Renderer::setClearColor(const Color& color) {
    assert(renderer_ != nullptr);

    SDL_SetRenderDrawColor(renderer_, color.red, color.green, color.blue, color.alpha);
}

void Renderer::clear() {
    clear({0, 0, 0, 255});
}

void Renderer::clear(const Color& color) {
    assert(renderer_ != nullptr);

    setClearColor(color);
    SDL_RenderClear(renderer_);
}

void Renderer::render(const Texture& texture, const Vector2& position) {
    auto size = texture.getSize();

    SDL_Rect offset{
        static_cast<int>(position.x),
        static_cast<int>(position.y),
        static_cast<int>(size.width),
        static_cast<int>(size.height)
    };

    SDL_RenderCopy(renderer_, texture, nullptr, &offset);
}

void Renderer::render(const Texture& texture, const Transform& transform) {
    auto size = texture.getSize();

    SDL_Rect offset{
        static_cast<int>(transform.position.x),
        static_cast<int>(transform.position.y),
        static_cast<int>(size.width * transform.scale.x),
        static_cast<int>(size.height * transform.scale.y)
    };

    SDL_Point center{
        static_cast<int>(transform.origin.x),
        static_cast<int>(transform.origin.y)
    };

    SDL_RenderCopyEx(renderer_, texture, nullptr, &offset, transform.angle, &center, transform.flip);
}

void Renderer::present() {
    assert(renderer_ != nullptr);

    SDL_RenderPresent(renderer_);
}

} /* namespace sdl */
} /* namespace mxg */
