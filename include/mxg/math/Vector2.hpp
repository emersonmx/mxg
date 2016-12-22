#ifndef MXG_MATH_VECTOR2_HPP_
#define MXG_MATH_VECTOR2_HPP_

namespace mxg {
namespace math {

template<typename T>
class Vector2 {
    public:
        Vector2();
        Vector2(const T t_x, const T t_y);
        template<typename U>
        explicit Vector2(const Vector2<U>& vector);

        T x = T();
        T y = T();
};

template <typename T>
Vector2<T> operator -(const Vector2<T>& right);

template <typename T>
Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right);

template <typename T>
Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right);

template <typename T>
Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right);

template <typename T>
Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right);

template <typename T>
Vector2<T> operator *(const Vector2<T>& left, T right);

template <typename T>
Vector2<T> operator *(T left, const Vector2<T>& right);

template <typename T>
Vector2<T>& operator *=(Vector2<T>& left, T right);

template <typename T>
Vector2<T> operator /(const Vector2<T>& left, T right);

template <typename T>
Vector2<T>& operator /=(Vector2<T>& left, T right);

template <typename T>
bool operator ==(const Vector2<T>& left, const Vector2<T>& right);

template <typename T>
bool operator !=(const Vector2<T>& left, const Vector2<T>& right);

#include "mxg/math/Vector2-inl.hpp"

typedef Vector2<int> Vector2i;
typedef Vector2<float> Vector2f;

} /* namespace math */
} /* namespace mxg */
#endif /* MXG_MATH_VECTOR2_HPP_ */
