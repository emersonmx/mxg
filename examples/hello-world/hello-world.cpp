#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include <mxg/sdl/Window.hpp>
#include <mxg/sdl/Renderer.hpp>
#include <mxg/sdl/TextureLoader.hpp>
#include <mxg/Clock.hpp>

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

    mxg::Clock clock;

    mxg::Vector2 position = windowSize / 2;
    mxg::Vector2 velocity{1, 1};
    int speed = 200;

    bool running = true;
    while (running) {
        float delta = clock.restart().asSeconds();

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        if (position.x < 0 || position.x > windowSize.width) {
            velocity.x = -velocity.x;
        }
        if (position.y < 0 || position.y > windowSize.height) {
            velocity.y = -velocity.y;
        }

        position += velocity * speed * delta;

        renderer.clear();
        renderer.render(texture, position - texture.getSize() / 2);
        renderer.present();
        SDL_Delay(16);
    }

    renderer.destroy();
    window.destroy();

    IMG_Quit();
    SDL_Quit();

    return 0;
}
