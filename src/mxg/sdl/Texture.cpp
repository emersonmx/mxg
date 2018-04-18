#include <mxg/sdl/Texture.hpp>

namespace mxg {
namespace sdl {

Texture::Texture(SDL_Texture* texture, const Size& size)
    : texture_(texture), size_(size) {}

void Texture::destroy() {
    SDL_DestroyTexture(texture_);
    texture_ = nullptr;
}

} /* namespace sdl */
} /* namespace mxg */
