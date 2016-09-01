#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "mxg/DefaultState.hpp"
#include "mxg/Game.hpp"

using ::testing::AnyNumber;
using ::testing::AtLeast;
using ::testing::AtMost;
using ::testing::Invoke;
using ::testing::Sequence;
using ::testing::Return;

class MockGame : public mxg::Game {
    public:
        MOCK_METHOD0(tick, void());
};

class MockState : public mxg::State {
    public:
        MOCK_METHOD0(create, void());
        MOCK_METHOD0(destroy, void());
        MOCK_METHOD0(enter, void());
        MOCK_METHOD0(exit, void());
        MOCK_METHOD0(tick, void());
};

class GameTest : public ::testing::Test {
    protected:
        GameTest() {
            EXPECT_CALL(game_, tick())
                .Times(AtMost(10));

            ON_CALL(game_, tick())
                .WillByDefault(Invoke([&](){
                    game_.getState()->tick();
                }));
        }
        virtual ~GameTest() {}

        MockGame game_;
};

TEST_F(GameTest, CheckGetAndSetState) {
    mxg::DefaultState state;
    game_.setState(state);
    ASSERT_EQ(game_.getState(), &state);
}

TEST_F(GameTest, NullAfterClearState) {
    mxg::DefaultState state;
    game_.setState(state);
    ASSERT_EQ(game_.getState(), &state);
    game_.clearState();
    ASSERT_EQ(game_.getState(), nullptr);
}

TEST_F(GameTest, JustCallTheEnterEventWhenItIsTheFirstState) {
    MockState state;

    EXPECT_CALL(state, enter())
        .Times(1);

    game_.setState(state);
}

TEST_F(GameTest, CallEnterAndExit) {
    MockState firstState;
    MockState secondState;

    Sequence sequence;
    EXPECT_CALL(firstState, enter())
        .Times(1);
    EXPECT_CALL(firstState, exit())
        .Times(1)
        .InSequence(sequence);
    EXPECT_CALL(secondState, enter())
        .Times(1)
        .InSequence(sequence);

    game_.setState(firstState);
    game_.setState(secondState);
}

TEST_F(GameTest, RunOk) {
    MockState state;

    Sequence stateSequence;
    EXPECT_CALL(state, create())
        .Times(1)
        .InSequence(stateSequence);
    EXPECT_CALL(state, enter())
        .Times(1)
        .InSequence(stateSequence);
    EXPECT_CALL(state, tick())
        .Times(AtLeast(1))
        .InSequence(stateSequence);
    EXPECT_CALL(state, destroy())
        .Times(1)
        .InSequence(stateSequence);
    EXPECT_CALL(state, exit())
        .Times(AnyNumber());
    ON_CALL(state, tick())
        .WillByDefault(Invoke([&](){
            game_.exit();
        }));

    state.create();

    game_.setState(state);
    EXPECT_EQ(game_.run(), 0);

    state.destroy();
}
