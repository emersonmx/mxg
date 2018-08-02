#ifndef MXG_SDL2_TEXTURE_HPP_
#define MXG_SDL2_TEXTURE_HPP_

#include <memory>
#include <iostream>

#include <SDL2/SDL_render.h>

#include <mxg/Size.hpp>

namespace mxg {
namespace sdl2 {

struct SDLTextureDeleter {
    void operator()(SDL_Texture* texture) {
        SDL_DestroyTexture(texture);
        std::cout << "Destroy texture" << texture << std::endl;
    }
};

using SDLTexturePtr = std::unique_ptr<SDL_Texture, SDLTextureDeleter>;

class Texture {
public:
    Texture(SDL_Texture* texture);

    Size getSize() const;
    SDL_Texture* getContents() const;

private:
    SDLTexturePtr texture_{};
};

} /* namespace sdl2 */
} /* namespace mxg */
#endif /* MXG_SDL2_TEXTURE_HPP_ */
