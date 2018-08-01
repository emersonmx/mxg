#ifndef MXG_SDL2_WINDOW_HPP_
#define MXG_SDL2_WINDOW_HPP_

#include <memory>

#include <SDL2/SDL_video.h>

#include <mxg/Size.hpp>
#include <mxg/Window.hpp>

namespace mxg {
namespace sdl2 {

struct SDLWindowDeleter {
    void operator()(SDL_Window* window) {
        SDL_DestroyWindow(window);
    }
};

class Window : public mxg::Window {
public:
    using SDLWindowPtr = std::unique_ptr<SDL_Window, SDLWindowDeleter>;

    Window() = default;
    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    ~Window() override;
    bool isOpen() const override;
    std::string getTitle() const override;
    Size getSize() const override;

    void create(const std::string& title, const Size& size) override;
    void destroy() override;

private:
    SDLWindowPtr window_{};
};

} /* namespace sdl2 */
} /* namespace mxg */
#endif /* MXG_SDL2_WINDOW_HPP_ */
