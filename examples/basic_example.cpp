#include <memory>

#include <mxg/sdl2/Engine.hpp>

int main() {
    std::unique_ptr<mxg::Engine> engine = std::make_unique<mxg::sdl2::Engine>();
    engine->initialize();

    // {
    //     mxg::Window window;
    //     window.create("Basic Example", {800, 600});
    // }

    engine->initialize();
    return 0;
}
