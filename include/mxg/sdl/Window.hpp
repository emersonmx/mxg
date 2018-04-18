#ifndef MXG_SDL_WINDOW_HPP_
#define MXG_SDL_WINDOW_HPP_

#include <string>

#include <SDL_video.h>

#include <mxg/Size.hpp>

namespace mxg {
namespace sdl {

class Window {
public:
    Window() = default;

    bool isOpen() const;
    std::string getTitle() const;
    Size getSize() const;

    void create(const std::string& title, const Size& size);
    void close();

    SDL_Window* get() const { return window_; }
    operator SDL_Window*() const { return window_; }

private:
    SDL_Window* window_{};
};

} /* namespace sdl */
} /* namespace mxg */
#endif /* MXG_SDL_WINDOW_HPP_ */
