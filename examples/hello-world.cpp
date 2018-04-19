#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include <mxg/sdl/Window.hpp>
#include <mxg/sdl/Renderer.hpp>
#include <mxg/sdl/TextureLoader.hpp>

int main() {
    srand(time(nullptr));

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Couldn't start SDL\n\tError: " << SDL_GetError() << std::endl;
        return 0;
    }

    int imgFlags = IMG_INIT_PNG;
    if ((IMG_Init(imgFlags) & imgFlags) != imgFlags) {
        std::cout << "Couldn't start SDL_Image\n\tError: " << IMG_GetError() << std::endl;
        return 0;
    }

    mxg::sdl::Window window;
    window.create("Hello World", {640, 480});
    auto windowSize = window.getSize();

    mxg::sdl::Renderer renderer{window};
    mxg::sdl::TextureLoader textureLoader{renderer};
    mxg::sdl::Texture texture = textureLoader.load("assets/awful-smile.png");

    renderer.clear();
    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        mxg::Vector2 position = {
            static_cast<float>(rand() % windowSize.width),
            static_cast<float>(rand() % windowSize.height),
        };
        position -= texture.getSize() / 2;
        renderer.render(texture, position);

        SDL_Delay(10);
        renderer.present();
    }

    renderer.destroy();
    window.close();

    IMG_Quit();
    SDL_Quit();

    return 0;
}
