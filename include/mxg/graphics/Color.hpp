// Copyright (C) 2016 Emerson Max de Medeiros Silva
//
// Permission is hereby granted, free of charge, to any person obtaining
// a copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
// OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
