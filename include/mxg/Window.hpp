#ifndef MXG_WINDOW_HPP_
#define MXG_WINDOW_HPP_

#include <string>

#include <mxg/Size.hpp>

namespace mxg {

class Window {
public:
    virtual ~Window() = default;
    virtual bool isOpen() const = 0;
    virtual std::string getTitle() const = 0;
    virtual Size getSize() const = 0;

    virtual void create(const std::string& title, const Size& size) = 0;
    virtual void destroy() = 0;
};

} /* namespace mxg */
#endif /* MXG_WINDOW_HPP_ */
