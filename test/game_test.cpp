#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "mxg/application/DefaultState.hpp"
#include "mxg/application/Game.hpp"

using ::testing::AnyNumber;
using ::testing::AtLeast;
using ::testing::Invoke;
using ::testing::Sequence;

class MockGame : public mxg::application::Game {
    public:
        MOCK_METHOD0(tick, void());
};

class MockState : public mxg::application::State {
    public:
        MOCK_METHOD0(enter, void());
        MOCK_METHOD0(exit, void());
        MOCK_METHOD0(tick, void());
};

class GameTest : public ::testing::Test {
    public:
        GameTest() {
            EXPECT_CALL(game, tick())
                .Times(AtLeast(0));

            ON_CALL(game, tick())
                .WillByDefault(Invoke([&](){
                    game.getState()->tick();
                }));
        }
        virtual ~GameTest() {}

        MockGame game;
};

TEST_F(GameTest, SetState) {
    mxg::application::DefaultState state;
    game.setState(state);
    ASSERT_EQ(game.getState(), &state);
}

TEST_F(GameTest, DontThrowErrorWhenNullState) {
    game.tick();
}

TEST_F(GameTest, OnSetStateCallEnter) {
    MockState state;

    EXPECT_CALL(state, enter())
        .Times(1);

    game.setState(state);
}

TEST_F(GameTest, OnSetStateCallExitAndThenEnterWhenStateIsNotNull) {
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

TEST_F(GameTest, RunGame) {
    MockState state;

    Sequence stateSequence;
    EXPECT_CALL(state, enter())
        .Times(1)
        .InSequence(stateSequence);
    EXPECT_CALL(state, tick())
        .Times(AtLeast(1))
        .InSequence(stateSequence);
    EXPECT_CALL(state, exit())
        .Times(AnyNumber());
    ON_CALL(state, tick())
        .WillByDefault(Invoke([&](){
            game.exit();
        }));

    game.setState(state);
    EXPECT_EQ(game.run(), 0);
}
