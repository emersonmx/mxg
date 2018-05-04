#include <catch.hpp>

#include <SDL.h>
#include <SDL_image.h>

#include <mxg/sdl/Window.hpp>
#include <mxg/sdl/Renderer.hpp>
#include <mxg/sdl/TextureLoader.hpp>
#include <mxg/sdl/Transform.hpp>

TEST_CASE("Renderer can be used", "[sdl][renderer]") {
    REQUIRE(SDL_Init(SDL_INIT_VIDEO) == 0);

    mxg::sdl::Window window;

    window.create("Test Window", {640, 480});

    mxg::sdl::Renderer renderer;

    SECTION("creating without call create results in undefined behavior") {
        REQUIRE(renderer.get() == nullptr);
        renderer.create(window);
        REQUIRE(renderer.get() != nullptr);
    }
    SECTION("destroy invalidates renderer") {
        renderer.create(window);
        REQUIRE(renderer.get() != nullptr);
        renderer.destroy();
        REQUIRE(renderer.get() == nullptr);
    }
    SECTION("creating changes clear color to black") {
        renderer.create(window);
        mxg::Color color = renderer.getClearColor();
        REQUIRE(color.red == 0);
        REQUIRE(color.green == 0);
        REQUIRE(color.blue == 0);
        REQUIRE(color.alpha == 255);
    }
    SECTION("clearing with color changes clear color") {
        renderer.create(window);
        renderer.clear({255, 0, 0});
        renderer.present();
        mxg::Color color = renderer.getClearColor();
        REQUIRE(color.red == 255);
        REQUIRE(color.green == 0);
        REQUIRE(color.blue == 0);
        REQUIRE(color.alpha == 255);
    }
    SECTION("clearing without color changes clear color to black") {
        renderer.create(window);
        renderer.clear();
        renderer.present();
        mxg::Color color = renderer.getClearColor();
        REQUIRE(color.red == 0);
        REQUIRE(color.green == 0);
        REQUIRE(color.blue == 0);
        REQUIRE(color.alpha == 255);
    }
    SECTION("rendering shows texture in window") {
        int imgFlags = IMG_INIT_PNG;
        REQUIRE((IMG_Init(imgFlags) & imgFlags) == imgFlags);

        renderer.create(window);
        mxg::sdl::TextureLoader textureLoader{renderer};
        mxg::sdl::Texture texture = textureLoader.load("assets/color_squares.png");

        mxg::sdl::Transform t1;
        t1.position = {100, 100};
        t1.angle = 30;
        t1.scale = {3, 3};

        mxg::sdl::Transform t2;
        t2.position = {500, 100};
        t2.angle = 30;
        t2.scale = {3, 3};
        t2.flip = static_cast<SDL_RendererFlip>(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);

        renderer.clear();
        renderer.render(texture, t1);
        renderer.render(texture, t2);
        renderer.present();

        IMG_Quit();
    }

    renderer.destroy();
    window.destroy();

    SDL_Quit();
}
