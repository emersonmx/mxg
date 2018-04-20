#ifndef MXG_APPLICATION_HPP_
#define MXG_APPLICATION_HPP_

namespace mxg {

class Application {
public:
    virtual ~Application() {}

    int run() {
        create();

        while (running_) {
            tick();
        }

        destroy();
        return errorCode_;
    }

    void exit(const int errorCode = 0) {
        errorCode_ = errorCode;
        running_ = false;
    }

protected:
    virtual void create() {}
    virtual void destroy() {}
    virtual void tick() {}

private:
    int errorCode_{0};
    bool running_{true};
};

} /* namespace mxg */
#endif /* MXG_APPLICATION_HPP_ */
