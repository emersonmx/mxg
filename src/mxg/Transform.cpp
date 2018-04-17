#include <mxg/Transform.hpp>

namespace mxg {

Transform::Transform()
    : matrix_{1.0f, 0.0f, 0.0f,
              0.0f, 1.0f, 0.0f,
              0.0f, 0.0f, 1.0f} {}

Transform::Transform(float a00, float a01, float a02,
              float a10, float a11, float a12,
              float a20, float a21, float a22)
    : matrix_{a00, a01, a02,
              a10, a11, a12,
              a20, a21, a22} {}

const float* Transform::getMatrix() const {
    return matrix_;
}

} /* namespace mxg */
