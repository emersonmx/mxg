#ifndef MXG_RENDERER_HPP_
#define MXG_RENDERER_HPP_

#include <mxg/Vector2.hpp>
#include <mxg/Color.hpp>
#include <mxg/Texture.hpp>
#include <mxg/Window.hpp>

namespace mxg {

class Renderer {
public:
    virtual ~Renderer() = default;

    virtual Color getClearColor() const = 0;
    virtual void setClearColor(const Color& color) = 0;

    virtual void create(const Window& window) = 0;
    virtual void destroy() = 0;

    virtual void clear() = 0;
    virtual void clear(const Color& color) = 0;
    virtual void render(const Texture& texture, const Vector2& position) = 0;
    virtual void render(const Texture& texture,
                        const Vector2& position,
                        const float angle,
                        const Vector2& scale,
                        const Vector2& center) = 0;
    virtual void present() = 0;
};

} /* namespace mxg */
#endif /* MXG_RENDERER_HPP_ */
