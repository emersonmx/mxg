#ifndef MXG_SDL2_CORE_HPP_
#define MXG_SDL2_CORE_HPP_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

namespace mxg {
namespace sdl2 {

void initialize();
void finalize();

} /* namespace sdl2 */
} /* namespace mxg */
#endif /* MXG_SDL2_CORE_HPP_ */
