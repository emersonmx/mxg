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

TEST(State, CallCreateMethod) {
    MockState state; 
    EXPECT_CALL(state, create());
    state.create();
}

TEST(State, CallDestroyMethod) {
    MockDefaultState state; 
    EXPECT_CALL(state, destroy());
    state.destroy();
}

TEST(State, CallEnterMethod) {
    MockDefaultState state; 
    EXPECT_CALL(state, enter());
    state.enter();
}

TEST(State, CallExitMethod) {
    MockDefaultState state; 
    EXPECT_CALL(state, exit());
    state.exit();
}

TEST(State, CallTickMethod) {
    MockDefaultState state; 
    EXPECT_CALL(state, tick());
    state.tick();
}

TEST(DefaultState, CallCreateMethod) {
    MockState state; 
    EXPECT_CALL(state, create());
    state.create();
}

TEST(DefaultState, CallDestroyMethod) {
    MockDefaultState state; 
    EXPECT_CALL(state, destroy());
    state.destroy();
}

TEST(DefaultState, CallEnterMethod) {
    MockDefaultState state; 
    EXPECT_CALL(state, enter());
    state.enter();
}

TEST(DefaultState, CallExitMethod) {
    MockDefaultState state; 
    EXPECT_CALL(state, exit());
    state.exit();
}

TEST(DefaultState, CallTickMethod) {
    MockDefaultState state; 
    EXPECT_CALL(state, tick());
    state.tick();
}
