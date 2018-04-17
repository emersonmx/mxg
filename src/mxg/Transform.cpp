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

} /* namespace mxg */
