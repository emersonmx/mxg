#include <mxg/sdl2/Texture.hpp>

namespace mxg {
namespace sdl2 {

Texture::Texture(SDL_Texture* texture) : texture_(texture) {}

Size Texture::getSize() const {
    int width, height;

    SDL_QueryTexture(
        getContents(),
        nullptr, nullptr,
        &width, &height
    );

    return Size{static_cast<uint32_t>(width), static_cast<uint32_t>(height)};
}

SDL_Texture* Texture::getContents() const {
    return texture_.get();
}

} /* namespace sdl2 */
} /* namespace mxg */
