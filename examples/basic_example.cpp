#include <memory>

#include <mxg/sdl2/Engine.hpp>
#include <mxg/sdl2/Window.hpp>

int main() {
    std::unique_ptr<mxg::Engine> engine = std::make_unique<mxg::sdl2::Engine>();
    engine->initialize();

    {
        std::unique_ptr<mxg::Window> window = std::make_unique<mxg::sdl2::Window>();
        window->create("Basic Example", {800, 600});

        SDL_Delay(2000);
    }

    engine->initialize();
    return 0;
}
