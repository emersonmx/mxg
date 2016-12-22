#ifndef MXG_GRAPHICS_COLOR_HPP_
#define MXG_GRAPHICS_COLOR_HPP_

#include <cstdint>

namespace mxg {
namespace graphics {

class Color {
    public:
        Color();
        Color(const std::uint8_t red, const std::uint8_t green,
              const std::uint8_t blue, const std::uint8_t alpha = 255);
        explicit Color(const std::uint32_t color);

        std::uint32_t toInteger() const;

        static const Color Black;
        static const Color White;
        static const Color Red;
        static const Color Green;
        static const Color Blue;
        static const Color Yellow;
        static const Color Magenta;
        static const Color Cyan;
        static const Color Transparent;

        std::uint8_t r;
        std::uint8_t g;
        std::uint8_t b;
        std::uint8_t a;
};

bool operator ==(const Color& left, const Color& right);
bool operator !=(const Color& left, const Color& right);
Color operator +(const Color& left, const Color& right);
Color operator -(const Color& left, const Color& right);
Color operator *(const Color& left, const Color& right);
Color& operator +=(Color& left, const Color& right);
Color& operator -=(Color& left, const Color& right);
Color& operator *=(Color& left, const Color& right);

} /* namespace graphics */
} /* namespace mxg */
#endif /* MXG_GRAPHICS_COLOR_HPP_ */
