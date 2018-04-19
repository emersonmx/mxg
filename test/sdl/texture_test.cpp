#include <catch.hpp>

#include <SDL.h>
#include <SDL_image.h>

#include <mxg/Vector2.hpp>
#include <mxg/sdl/Window.hpp>
#include <mxg/sdl/Renderer.hpp>
#include <mxg/sdl/Texture.hpp>
#include <mxg/sdl/TextureLoader.hpp>

TEST_CASE("Textures can be used", "[sdl][texture]") {
    REQUIRE(SDL_Init(SDL_INIT_VIDEO) == 0);
    int imgFlags = IMG_INIT_PNG;
    REQUIRE((IMG_Init(imgFlags) & imgFlags) == imgFlags);

    mxg::sdl::Window window;

    window.create("Test Window", {640, 480});

    mxg::sdl::Renderer renderer{window};
    mxg::sdl::TextureLoader textureLoader{renderer};

    SECTION("creating texture results in a invalid texture") {
        mxg::sdl::Texture texture;
        REQUIRE(texture.get() == nullptr);
        texture.destroy();
        REQUIRE(texture.get() == nullptr);
    }
    SECTION("creating texture from file results in a valid texture") {
        mxg::sdl::Texture texture = textureLoader.load("assets/color_squares.png");
        REQUIRE(texture.get() != nullptr);
        texture.destroy();
        REQUIRE(texture.get() == nullptr);
    }
    SECTION("querying texture size results in a Size") {
        mxg::sdl::Texture texture = textureLoader.load("assets/color_squares.png");
        auto size = texture.getSize();
        REQUIRE(size == mxg::Size{32, 32});
    }

    renderer.destroy();
    window.close();

    IMG_Quit();
    SDL_Quit();
}
