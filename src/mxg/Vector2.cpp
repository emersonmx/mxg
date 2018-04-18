#include <mxg/Vector2.hpp>

namespace mxg {

Vector2::Vector2() : x(0.0f), y(0.0f) {}

Vector2::Vector2(float aX, float aY) : x(aX), y(aY) {}

bool operator == (const Vector2& left, const Vector2& right) {
    return left.x == right.x && left.y == right.y;
}

bool operator != (const Vector2& left, const Vector2& right) {
    return left.x != right.x || left.y != right.y;
}

Vector2 operator + (const Vector2& left, const Vector2& right) {
    return Vector2{left.x + right.x, left.y + right.y};
}

Vector2 operator += (Vector2& left, const Vector2& right) {
    left.x += right.x;
    left.y += right.y;
    return left;
}

Vector2 operator - (const Vector2& left, const Vector2& right) {
    return Vector2{left.x - right.x, left.y - right.y};
}

Vector2 operator - (const Vector2& left) {
    return Vector2{-left.x, -left.y};
}

Vector2 operator -= (Vector2& left, const Vector2& right) {
    left.x -= right.x;
    left.y -= right.y;
    return left;
}

Vector2 operator * (const Vector2& left, const float right) {
    return Vector2{left.x * right, left.y * right};
}

Vector2 operator * (const float left, const Vector2& right) {
    return Vector2{right.x * left, right.y * left};
}

Vector2 operator *= (Vector2& left, const float right) {
    left.x *= right;
    left.y *= right;
    return left;
}

Vector2 operator / (const Vector2& left, const float right) {
    return Vector2{left.x / right, left.y / right};
}

Vector2 operator /= (Vector2& left, const float right) {
    left.x /= right;
    left.y /= right;
    return left;
}

} /* namespace mxg */