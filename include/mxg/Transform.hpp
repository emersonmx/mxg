#ifndef MXG_TRANSFORM_HPP_
#define MXG_TRANSFORM_HPP_

#include <mxg/Vector2.hpp>

namespace mxg {

class Transform {
public:
    Transform();
    Transform(float a00, float a01, float a02,
              float a10, float a11, float a12,
              float a20, float a21, float a22);

    const float* getMatrix() const;
    Transform getInverse() const;

    Transform& combine(const Transform& transform);
    Transform& translate(const Vector2& offset);
    Transform& rotate(float radians);
    Transform& scale(const Vector2& factors);

private:
    float matrix_[16];
};

Transform operator *(const Transform& left, const Transform& right);
Transform& operator *=(Transform& left, const Transform& right);
bool operator ==(const Transform& left, const Transform& right);
bool operator !=(const Transform& left, const Transform& right);

} /* namespace mxg */
#endif /* MXG_TRANSFORM_HPP_ */
