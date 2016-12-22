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

#ifndef MXG_MATH_RECTANGLE_HPP_
#define MXG_MATH_RECTANGLE_HPP_

#include <algorithm>

#include "mxg/math/Vector2.hpp"

namespace mxg {
namespace math {

template <typename T>
class Rectangle {
    public:
        Rectangle();
        Rectangle(const T t_left, const T t_top,
                  const T t_width, const T t_height);
        Rectangle(const Vector2<T>& position, const Vector2<T>& size);

        template <typename U>
        explicit Rectangle(const Rectangle<U>& rectangle);

        bool contains(const T x, const T y) const;
        bool contains(const Vector2<T>& point) const;
        bool intersects(const Rectangle<T>& rectangle) const;
        bool intersects(const Rectangle<T>& rectangle, Rectangle<T>& intersection) const;

        T left{};
        T top{};
        T width{};
        T height{};
};

template <typename T>
bool operator ==(const Rectangle<T>& left, const Rectangle<T>& right);

template <typename T>
bool operator !=(const Rectangle<T>& left, const Rectangle<T>& right);

#include "mxg/math/Rectangle-inl.hpp"

// Create typedefs for the most common types
typedef Rectangle<int> RectangleInt;
typedef Rectangle<float> RectangleFloat;

} /* namespace math */
} /* namespace mxg */
#endif /* MXG_MATH_RECTANGLE_HPP_ */
