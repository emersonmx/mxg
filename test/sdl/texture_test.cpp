#include <catch.hpp>

#include <SDL.h>
#include <SDL_image.h>

#include <mxg/Vector2.hpp>
#include <mxg/sdl/Window.hpp>
#include <mxg/sdl/Renderer.hpp>
#include <mxg/sdl/Texture.hpp>

mxg::sdl::Texture loadTexture(SDL_Renderer* renderer, const std::string& filename) {
    SDL_Surface* loadedSurface = IMG_Load(filename.c_str());
    if (loadedSurface == nullptr) {
        return mxg::sdl::Texture{};
    }

    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    uint32_t width = loadedSurface->w >= 0 ? loadedSurface->w : 0;
    uint32_t height = loadedSurface->h >= 0 ? loadedSurface->h : 0;
    mxg::Size size{width, height};

    SDL_FreeSurface(loadedSurface);

    return mxg::sdl::Texture{newTexture, size};
}

TEST_CASE("Textures can be used", "[texture]") {
    REQUIRE(SDL_Init(SDL_INIT_VIDEO) == 0);
    int imgFlags = IMG_INIT_PNG;
    REQUIRE((IMG_Init(imgFlags) & imgFlags) == imgFlags);

    mxg::sdl::Window window;

    window.create("Test Window", {640, 480});

    mxg::sdl::Renderer renderer{window};

    SECTION("creating texture results in a invalid texture") {
        mxg::sdl::Texture texture;
        REQUIRE(texture.get() == nullptr);
        texture.destroy();
        REQUIRE(texture.get() == nullptr);
    }
    SECTION("creating texture from SDL_Texture results in a valid texture") {
        mxg::sdl::Texture texture = loadTexture(renderer, "assets/color_squares.png");
        REQUIRE(texture.get() != nullptr);
        texture.destroy();
        REQUIRE(texture.get() == nullptr);
    }
    SECTION("querying texture size results in a Size") {
        mxg::sdl::Texture texture = loadTexture(renderer, "assets/color_squares.png");
        auto size = texture.getSize();
        REQUIRE(size == mxg::Size{32, 32});
    }

    renderer.destroy();
    window.close();

    IMG_Quit();
    SDL_Quit();
}
