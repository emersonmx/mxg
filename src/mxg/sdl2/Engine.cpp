#include <mxg/sdl2/Engine.hpp>

namespace mxg {
namespace sdl2 {

void Engine::initialize() {
    initializeSDL();
    initializeSDLImage();
    initializeSDLTTF();
    initializeSDLMixer();

    initialized_ = true;
}

void Engine::finalize() {
    if (!initialized_) {
        return;
    }

    Mix_Quit();
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void Engine::initializeSDL() {
    Uint32 flags = SDL_INIT_EVERYTHING;
    if (SDL_Init(flags) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
            "Couldn't initialize SDL2. Error: %s", SDL_GetError());
    }
}

void Engine::initializeSDLImage() {
    Uint32 flags = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP;;
    if (!(IMG_Init(flags) & flags)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
            "Couldn't initialize SDL2 Image. Error: %s", IMG_GetError());
    }
}

void Engine::initializeSDLTTF() {
    if (TTF_Init() == -1) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
            "Couldn't initialize SDL2 TTF. Error: %s", TTF_GetError());
    }
}

void Engine::initializeSDLMixer() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
            "Couldn't open audio. Error: %s", Mix_GetError());
    }
}

} /* namespace sdl2 */
} /* namespace mxg */
