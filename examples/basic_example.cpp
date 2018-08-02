#include <memory>

#include <mxg/sdl2/Core.hpp>
#include <mxg/sdl2/Window.hpp>

int main() {
    mxg::sdl2::initialize();

    {
        std::unique_ptr<mxg::Window> window = std::make_unique<mxg::sdl2::Window>();
        window->create("Basic Example", {800, 600});

        SDL_Delay(2000);
    }

    mxg::sdl2::finalize();

    return 0;
}
