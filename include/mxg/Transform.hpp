#ifndef MXG_TRANSFORM_HPP_
#define MXG_TRANSFORM_HPP_

namespace mxg {

class Transform {
public:
    Transform();
    Transform(float a00, float a01, float a02,
              float a10, float a11, float a12,
              float a20, float a21, float a22);

    const float* getMatrix() const;

private:
    float matrix_[16];
};

bool operator ==(const Transform& left, const Transform& right);
bool operator !=(const Transform& left, const Transform& right);

} /* namespace mxg */
#endif /* MXG_TRANSFORM_HPP_ */
