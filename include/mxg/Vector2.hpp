#ifndef MXG_VECTOR2_HPP_
#define MXG_VECTOR2_HPP_

namespace mxg {

class Vector2 {
public:
    Vector2();
    Vector2(float x, float y);

    void normalize();
    Vector2 normalized() const;

    float x;
    float y;
};

Vector2 operator + (const Vector2& left, const Vector2& right);
Vector2 operator += (Vector2& left, const Vector2& right);
Vector2 operator - (const Vector2& left, const Vector2& right);
Vector2 operator - (const Vector2& left);
Vector2 operator -= (Vector2& left, const Vector2& right);
Vector2 operator * (const Vector2& left, const float right);
Vector2 operator * (const float left, const Vector2& right);
Vector2 operator *= (Vector2& left, const float right);
Vector2 operator / (const Vector2& left, const float right);
Vector2 operator /= (Vector2& left, const float right);

bool operator == (const Vector2& left, const Vector2& right);
bool operator != (const Vector2& left, const Vector2& right);

} /* namespace mxg */
#endif /* MXG_VECTOR2_HPP_ */
