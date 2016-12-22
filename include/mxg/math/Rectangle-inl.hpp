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

template <typename T>
Rectangle<T>::Rectangle()
    : left  (0), top   (0), width (0), height(0) {}

template <typename T>
Rectangle<T>::Rectangle(const T t_left, const T t_top,
                        const T t_width, const T t_height)
    : left(t_left), top(t_top), width(t_width), height(t_height) {}

template <typename T>
Rectangle<T>::Rectangle(const Vector2<T>& position, const Vector2<T>& size)
    : left(position.x), top(position.y), width(size.x), height(size.y) {}

template <typename T>
template <typename U>
Rectangle<T>::Rectangle(const Rectangle<U>& rectangle)
    : left(static_cast<T>(rectangle.left)), top(static_cast<T>(rectangle.top)),
      width(static_cast<T>(rectangle.width)),
      height(static_cast<T>(rectangle.height)) {}

template <typename T>
bool Rectangle<T>::contains(const T x, const T y) const {
    T minX = std::min(left, static_cast<T>(left + width));
    T maxX = std::max(left, static_cast<T>(left + width));
    T minY = std::min(top, static_cast<T>(top + height));
    T maxY = std::max(top, static_cast<T>(top + height));

    return (x >= minX) && (x < maxX) && (y >= minY) && (y < maxY);
}

template <typename T>
bool Rectangle<T>::contains(const Vector2<T>& point) const {
    return contains(point.x, point.y);
}

template <typename T>
bool Rectangle<T>::intersects(const Rectangle<T>& rectangle) const {
    Rectangle<T> intersection;
    return intersects(rectangle, intersection);
}

template <typename T>
bool Rectangle<T>::intersects(const Rectangle<T>& rectangle,
        Rectangle<T>& intersection) const {
    T r1MinX = std::min(left, static_cast<T>(left + width));
    T r1MaxX = std::max(left, static_cast<T>(left + width));
    T r1MinY = std::min(top, static_cast<T>(top + height));
    T r1MaxY = std::max(top, static_cast<T>(top + height));

    T r2MinX = std::min(rectangle.left,
            static_cast<T>(rectangle.left + rectangle.width));
    T r2MaxX = std::max(rectangle.left,
            static_cast<T>(rectangle.left + rectangle.width));
    T r2MinY = std::min(rectangle.top,
            static_cast<T>(rectangle.top + rectangle.height));
    T r2MaxY = std::max(rectangle.top,
            static_cast<T>(rectangle.top + rectangle.height));

    T interLeft   = std::max(r1MinX, r2MinX);
    T interTop    = std::max(r1MinY, r2MinY);
    T interRight  = std::min(r1MaxX, r2MaxX);
    T interBottom = std::min(r1MaxY, r2MaxY);

    if ((interLeft < interRight) && (interTop < interBottom)) {
        intersection = Rectangle<T>(interLeft, interTop, interRight - interLeft,
                                    interBottom - interTop);
        return true;
    } else {
        intersection = Rectangle<T>(0, 0, 0, 0);
        return false;
    }
}

template <typename T>
inline bool operator ==(const Rectangle<T>& left, const Rectangle<T>& right) {
    return (left.left == right.left) && (left.width == right.width) &&
           (left.top == right.top) && (left.height == right.height);
}

template <typename T>
inline bool operator !=(const Rectangle<T>& left, const Rectangle<T>& right) {
    return !(left == right);
}
