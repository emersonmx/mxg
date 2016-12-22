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

#ifndef MXG_MATH_CIRCLE_HPP_
#define MXG_MATH_CIRCLE_HPP_

#include "mxg/math/Vector2.hpp"
#include "mxg/math/Utils.hpp"

namespace mxg {
namespace math {

template<typename T>
class Circle {
    public:
        Circle() {}

        Circle(const T t_x, const T t_y, const T t_radius)
            : x(t_x), y(t_y), radius(t_radius) {}

        bool contains(const T t_x, const T t_y) const {
            const T dx = x - t_x;
            const T dy = y - t_y;
            return dx*dx + dy*dy <= radius*radius;
        }

        bool contains(const Circle<T>& circle) const {
            const T radiusDiff = radius - circle.radius;
            if (radiusDiff < 0.0f) {
                return false;
            }
            const T dx = x - circle.x;
            const T dy = y - circle.y;
            const T dst = dx*dx + dy*dy;
            const T radiusSum = radius + circle.radius;
            return !(radiusDiff * radiusDiff < dst)
                && (dst < radiusSum * radiusSum);
        }

        bool intersects(const Circle<T>& circle) const {
            T dx = x - circle.x;
            T dy = y - circle.y;
            T distance = dx*dx + dy*dy;
            T radiusSum = radius + circle.radius;
            return distance < radiusSum*radiusSum;
        }

        T x{};
        T y{};
        T radius{};
};

template<typename T>
bool operator ==(const Circle<T>& left, const Circle<T>& right) {
    return (left.x == right.x) &&
           (left.y == right.y) &&
           (left.radius == right.radius);
}

template<typename T>
bool operator !=(const Circle<T>& left, const Circle<T>& right) {
    return !(left == right);
}

} /* namespace math */
} /* namespace mxg */
#endif /* MXG_MATH_CIRCLE_HPP_ */
