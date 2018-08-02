#include <memory>

#include <mxg/sdl2/Core.hpp>
#include <mxg/sdl2/Window.hpp>
#include <mxg/sdl2/Renderer.hpp>

int main() {
    mxg::sdl2::initialize();

    {
        mxg::sdl2::Window window;
        window.create("Basic Example", {800, 600});

        mxg::sdl2::Renderer renderer(window.getContents());
        renderer.create();

        bool running = true;
        while (running) {
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    running = false;
                }
            }

            renderer.clear();
            renderer.present();
        }
    }

    mxg::sdl2::finalize();

    return 0;
}
