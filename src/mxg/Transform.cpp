#include <mxg/Transform.hpp>

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
