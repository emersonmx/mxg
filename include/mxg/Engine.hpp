#ifndef MXG_ENGINE_HPP_
#define MXG_ENGINE_HPP_

namespace mxg {

class Engine {
public:
    virtual ~Engine() = default;
    virtual void initialize() = 0;
    virtual void finalize() = 0;
};

} /* namespace mxg */
#endif /* MXG_ENGINE_HPP_ */
