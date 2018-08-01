#ifndef MXG_SDL2_ENGINE_HPP_
#define MXG_SDL2_ENGINE_HPP_

#include <mxg/Engine.hpp>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

namespace mxg {
namespace sdl2 {

class Engine : public mxg::Engine {
public:
    void initialize() override;
    void finalize() override;

protected:
    virtual void initializeSDL();
    virtual void initializeSDLImage();
    virtual void initializeSDLTTF();
    virtual void initializeSDLMixer();

    bool initialized_{false};
};

} /* namespace sdl2 */
} /* namespace mxg */
#endif /* MXG_SDL2_ENGINE_HPP_ */
