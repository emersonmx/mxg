#include <mxg/sdl/TextureLoader.hpp>

#include <SDL_render.h>
#include <SDL_image.h>

#include <mxg/Size.hpp>

namespace mxg {
namespace sdl {

TextureLoader::TextureLoader(const Renderer& renderer)
    : renderer_(renderer) {}

Texture TextureLoader::load(const std::string& filename) {
    SDL_Surface* loadedSurface = IMG_Load(filename.c_str());
    if (loadedSurface == nullptr) {
        return Texture{};
    }

    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer_, loadedSurface);
    uint32_t width = loadedSurface->w >= 0 ? loadedSurface->w : 0;
    uint32_t height = loadedSurface->h >= 0 ? loadedSurface->h : 0;
    Size size{width, height};

    SDL_FreeSurface(loadedSurface);

    return Texture{newTexture, size};
}

} /* namespace sdl */
} /* namespace mxg */
