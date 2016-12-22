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
