#ifndef MXG_MATH_ELLIPSE_HPP_
#define MXG_MATH_ELLIPSE_HPP_

#include <cmath>

namespace mxg {
namespace math {

template<typename T>
class Ellipse {
    public:
        Ellipse() {}

        Ellipse(const T t_x, const T t_y, const T t_width, const T t_height)
            : x(t_x), y(t_y), width(t_width), height(t_height) {}

        void set(const T t_x, const T t_y, const T t_width, const T t_height) {
            x = t_x;
            y = t_y;
            width = t_width;
            height = t_height;
        }

        void setPosition(const T t_x, const T t_y) {
            x = t_x;
            y = t_y;
        }

        void setSize(const T t_width, const T t_height) {
            width = t_width;
            height = t_height;
        }

        bool contains(const T t_x, const T t_y) const {
            const T dx = t_x - x;
            const T dy = t_y - y;
            return ((dx*dx) / (width*0.5f * width*0.5f) + (dy*dy) /
                    (height*0.5f * height*0.5f)) <= 1.0f;
        }

        T circumference() const {
            T a = width / 2;
            T b = height / 2;
            if (a * 3 > b || b * 3 > a) {
                return mxg::math::utils::PI *
                    ((3 * (a + b)) - sqrt((3 * a + b) * (a + 3 * b)));
            } else {
                return mxg::math::utils::PI2 * sqrt((a * a + b * b) / 2);
            }
        }

        T area() const {
            return mxg::math::utils::PI * (width * height) / 4;
        }

        T x = T();
        T y = T();
        T width = T();
        T height = T();
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
