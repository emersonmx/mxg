#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "mxg/DefaultState.hpp"

class MockState : public mxg::State {
    public:
        MOCK_METHOD0(create, void());
        MOCK_METHOD0(destroy, void());
        MOCK_METHOD0(enter, void());
        MOCK_METHOD0(exit, void());
        MOCK_METHOD0(tick, void());
};

class MockDefaultState : public mxg::DefaultState {
    public:
        MOCK_METHOD0(create, void());
        MOCK_METHOD0(destroy, void());
        MOCK_METHOD0(enter, void());
        MOCK_METHOD0(exit, void());
        MOCK_METHOD0(tick, void());
};

TEST(StateTest, CallBasicMethods) {
    MockState state; 
    EXPECT_CALL(state, create());
    EXPECT_CALL(state, destroy());
    EXPECT_CALL(state, enter());
    EXPECT_CALL(state, exit());
    EXPECT_CALL(state, tick());
    state.create();
    state.destroy();
    state.enter();
    state.exit();
    state.tick();
}
