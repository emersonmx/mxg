#ifndef MXG_SDL_TEXTURELOADER_HPP_
#define MXG_SDL_TEXTURELOADER_HPP_

#include <string>

#include <mxg/sdl/Renderer.hpp>
#include <mxg/sdl/Texture.hpp>

namespace mxg {
namespace sdl {

class TextureLoader {
public:
    TextureLoader(const Renderer& renderer);

    Texture load(const std::string& filename);

private:
    Renderer renderer_{};
};

} /* namespace sdl */
} /* namespace mxg */
#endif /* MXG_SDL_TEXTURELOADER_HPP_ */
