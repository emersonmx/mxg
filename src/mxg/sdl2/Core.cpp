#include <mxg/Core.hpp>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

namespace mxg {

void Initialize() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
            "Couldn't initialize SDL2. Error: %s", SDL_GetError());
    }

    int imgFlags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP;
    if (!(IMG_Init(imgFlags) & imgFlags)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
            "Couldn't initialize SDL2 Image. Error: %s", IMG_GetError());
    }

    if (TTF_Init() == -1) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
            "Couldn't initialize SDL2 TTF. Error: %s", TTF_GetError());
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
            "Couldn't open audio. Error: %s", Mix_GetError());
    }
}

void Finalize() {
    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

} /* namespace mxg */
