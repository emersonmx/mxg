#ifndef MXG_RENDERER_HPP_
#define MXG_RENDERER_HPP_

#include <mxg/Color.hpp>
#include <mxg/Window.hpp>
#include <mxg/Texture.hpp>
#include <mxg/Transform.hpp>

namespace mxg {

class Renderer {
public:
    virtual void create(const Window& window) = 0;
    virtual void destroy() = 0;

    virtual Color getClearColor() const = 0;
    virtual void setClearColor(const Color& color) = 0;

    virtual void clear() = 0;
    virtual void clear(const Color& color) = 0;
    virtual void render(const Texture& texture, const Vector2& position) = 0;
    virtual void render(const Texture& texture, const Transform& transform) = 0;
    virtual void present() = 0;
};

} /* namespace mxg */
#endif /* MXG_RENDERER_HPP_ */
