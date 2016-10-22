#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "mxg/app/DefaultState.hpp"
#include "mxg/app/Game.hpp"

using ::testing::AnyNumber;
using ::testing::AtLeast;
using ::testing::AtMost;
using ::testing::Invoke;
using ::testing::Sequence;
using ::testing::Return;

class MockGame : public mxg::app::Game {
    public:
        MOCK_METHOD0(tick, void());
};

class MockState : public mxg::app::State {
    public:
        MOCK_METHOD0(create, void());
        MOCK_METHOD0(destroy, void());
        MOCK_METHOD0(enter, void());
        MOCK_METHOD0(exit, void());
        MOCK_METHOD0(tick, void());
};

class GameTest : public ::testing::Test {
    public:
        GameTest() {
            EXPECT_CALL(game, tick())
                .Times(AtMost(10));

            ON_CALL(game, tick())
                .WillByDefault(Invoke([&](){
                    game.getState()->tick();
                }));
        }
        virtual ~GameTest() {}

        MockGame game;
};

TEST_F(GameTest, CheckGetAndSetState) {
    mxg::app::DefaultState state;
    game.setState(state);
    ASSERT_EQ(game.getState(), &state);
}

TEST_F(GameTest, NullAfterClearState) {
    mxg::app::DefaultState state;
    game.setState(state);
    ASSERT_EQ(game.getState(), &state);
    game.clearState();
    ASSERT_EQ(game.getState(), nullptr);
}

TEST_F(GameTest, JustCallTheEnterEventWhenItIsTheFirstState) {
    MockState state;

    EXPECT_CALL(state, enter())
        .Times(1);

    game.setState(state);
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

    game.setState(firstState);
    game.setState(secondState);
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
            game.exit();
        }));

    state.create();

    game.setState(state);
    EXPECT_EQ(game.run(), 0);

    state.destroy();
}
