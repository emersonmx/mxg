#ifndef MXG_SDL2_WINDOW_HPP_
#define MXG_SDL2_WINDOW_HPP_

#include <memory>

#include <SDL2/SDL_video.h>

#include <mxg/Size.hpp>

namespace mxg {
namespace sdl2 {

struct SDLWindowDeleter {
    void operator()(SDL_Window* window) {
        SDL_DestroyWindow(window);
    }
};

using SDLWindowPtr = std::unique_ptr<SDL_Window, SDLWindowDeleter>;

class Window {
public:
    Window() = default;
    Window(SDL_Window* window);

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    bool isOpen() const;
    std::string getTitle() const;
    Size getSize() const;
    SDL_Window* getContents() const;

    void create(const std::string& title, const Size& size);
    void destroy();

private:
    SDLWindowPtr window_{};
};

} /* namespace sdl2 */
} /* namespace mxg */
#endif /* MXG_SDL2_WINDOW_HPP_ */
