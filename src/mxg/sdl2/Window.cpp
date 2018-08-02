#include <mxg/sdl2/Window.hpp>

#include <mxg/Exception.hpp>

namespace mxg {
namespace sdl2 {

Window::~Window() {
    destroy();
}

bool Window::isOpen() const {
    return static_cast<bool>(window_);
}

std::string Window::getTitle() const {
    return SDL_GetWindowTitle(getContents());
}

Size Window::getSize() const {
    int width{}, height{};
    SDL_GetWindowSize(getContents(), &width, &height);
    return Size{static_cast<uint32_t>(width), static_cast<uint32_t>(height)};
}

SDL_Window* Window::getContents() const {
    return window_.get();
}

void Window::create(const std::string& title, const Size& size) {
    window_.reset(
        SDL_CreateWindow(
            title.c_str(),
            SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            size.width, size.height,
            SDL_WINDOW_SHOWN
        )
    );
}

void Window::destroy() {
    window_.reset();
}

} /* namespace sdl2 */
} /* namespace mxg */
