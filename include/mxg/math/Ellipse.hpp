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

#ifndef MXG_MATH_ELLIPSE_HPP_
#define MXG_MATH_ELLIPSE_HPP_

#include <cmath>

#include "mxg/math/Vector2.hpp"

namespace mxg {
namespace math {

template<typename T>
class Ellipse {
    public:
        Ellipse() {}

        Ellipse(const T t_x, const T t_y, const T t_width, const T t_height)
            : x(t_x), y(t_y), width(t_width), height(t_height) {}

        bool contains(const T t_x, const T t_y) const {
            const T dx = t_x - x;
            const T dy = t_y - y;
            return ((dx*dx) / (width*0.5f * width*0.5f) + (dy*dy) /
                    (height*0.5f * height*0.5f)) <= 1.0f;
        }

        T x{};
        T y{};
        T width{};
        T height{};
};

template<typename T>
bool operator ==(const Ellipse<T>& left, const Ellipse<T>& right) {
    return (left.x == right.x) &&
           (left.y == right.y) &&
           (left.width == right.width) &&
           (left.height == right.height);
}

template<typename T>
bool operator !=(const Ellipse<T>& left, const Ellipse<T>& right) {
    return !(left == right);
}

} /* namespace math */
} /* namespace mxg */
#endif /* MXG_MATH_ELLIPSE_HPP_ */
