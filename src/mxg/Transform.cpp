#include <mxg/Transform.hpp>

#include <cmath>

namespace mxg {

Transform::Transform()
    : matrix_{1.0f, 0.0f, 0.0f, 0.0f,
              0.0f, 1.0f, 0.0f, 0.0f,
              0.0f, 0.0f, 1.0f, 0.0f,
              0.0f, 0.0f, 0.0f, 1.0f} {}

Transform::Transform(float a00, float a01, float a02,
                     float a10, float a11, float a12,
                     float a20, float a21, float a22)
    : matrix_{a00, a10, 0.0f, a20,
              a01, a11, 0.0f, a21,
              0.0f, 0.0f, 1.0f, 0.0f,
              a02, a12, 0.0f, a22} {}

const float* Transform::getMatrix() const {
    return matrix_;
}

Transform Transform::getInverse() const {
    float determinant = matrix_[0] * (matrix_[15] * matrix_[5] - matrix_[7] * matrix_[13]) -
                        matrix_[1] * (matrix_[15] * matrix_[4] - matrix_[7] * matrix_[12]) +
                        matrix_[3] * (matrix_[13] * matrix_[4] - matrix_[5] * matrix_[12]);

    if (determinant != 0.f) {
        return Transform( (matrix_[15] * matrix_[5] - matrix_[7] * matrix_[13]) / determinant,
                         -(matrix_[15] * matrix_[4] - matrix_[7] * matrix_[12]) / determinant,
                          (matrix_[13] * matrix_[4] - matrix_[5] * matrix_[12]) / determinant,
                         -(matrix_[15] * matrix_[1] - matrix_[3] * matrix_[13]) / determinant,
                          (matrix_[15] * matrix_[0] - matrix_[3] * matrix_[12]) / determinant,
                         -(matrix_[13] * matrix_[0] - matrix_[1] * matrix_[12]) / determinant,
                          (matrix_[7]  * matrix_[1] - matrix_[3] * matrix_[5])  / determinant,
                         -(matrix_[7]  * matrix_[0] - matrix_[3] * matrix_[4])  / determinant,
                          (matrix_[5]  * matrix_[0] - matrix_[1] * matrix_[4])  / determinant);
    }

    return Transform{};
}

Transform& Transform::combine(const Transform& transform) {
    const float* a = matrix_;
    const float* b = transform.matrix_;

    *this = Transform(a[0] * b[0]  + a[4] * b[1]  + a[12] * b[3],
                      a[0] * b[4]  + a[4] * b[5]  + a[12] * b[7],
                      a[0] * b[12] + a[4] * b[13] + a[12] * b[15],
                      a[1] * b[0]  + a[5] * b[1]  + a[13] * b[3],
                      a[1] * b[4]  + a[5] * b[5]  + a[13] * b[7],
                      a[1] * b[12] + a[5] * b[13] + a[13] * b[15],
                      a[3] * b[0]  + a[7] * b[1]  + a[15] * b[3],
                      a[3] * b[4]  + a[7] * b[5]  + a[15] * b[7],
                      a[3] * b[12] + a[7] * b[13] + a[15] * b[15]);

    return *this;
}

Transform& Transform::translate(const Vector2& offset) {
    Transform translation{1, 0, offset.x,
                          0, 1, offset.y,
                          0, 0, 1};
    return combine(translation);
}

Transform& Transform::rotate(float radians) {
    float cos = std::cos(radians);
    float sin = std::sin(radians);

    Transform rotation(cos, -sin, 0,
                       sin,  cos, 0,
                       0,    0,   1);

    return combine(rotation);
}

Transform& Transform::scale(const Vector2& factors) {
    Transform scaling{factors.x, 0,        0,
                          0,        factors.y, 0,
                          0,        0,        1};
    return combine(scaling);
}

bool operator ==(const Transform& left, const Transform& right)
{
    auto a = left.getMatrix();
    auto b = right.getMatrix();

    return ((a[0]  == b[0])  && (a[1]  == b[1])  && (a[3]  == b[3]) &&
            (a[4]  == b[4])  && (a[5]  == b[5])  && (a[7]  == b[7]) &&
            (a[12] == b[12]) && (a[13] == b[13]) && (a[15] == b[15]));
}

bool operator !=(const Transform& left, const Transform& right)
{
    return !(left == right);
}

} /* namespace mxg */
