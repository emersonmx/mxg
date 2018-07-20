#include <mxg/Core.hpp>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <mxg/Exception.hpp>

namespace mxg {

void Initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        throw Exception("Couldn't initialize SDL2. Error: " + SDL_GetError());
    }

    int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        throw Exception("Couldn't initialize SDL2 Image. Error: " + IMG_GetError());
    }

    if (TTF_Init() == -1) {
        throw Exception("Couldn't initialize SDL2 TTF. Error: " + TTF_GetError());
    }

    int mixFlags = MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG | MIX_INIT_MID;
    if (!(Mix_Init() & mixFlags)) {
        throw Exception("Couldn't initialize SDL2 Mixer. Error: " + Mix_GetError());
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
        throw Exception("Couldn't open audio. Error: " + Mix_GetError());
    }
}

void Finalize() {
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

} /* namespace mxg */
