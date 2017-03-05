#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "mxg/application/DefaultState.hpp"
#include "mxg/application/StateApplication.hpp"

using ::testing::AnyNumber;
using ::testing::AtLeast;
using ::testing::AnyNumber;
using ::testing::Invoke;
using ::testing::Sequence;

class MockStateApplication : public mxg::application::StateApplication {
    public:
        MOCK_METHOD0(tick, void());
};

class MockState : public mxg::application::State {
    public:
        MOCK_METHOD0(enter, void());
        MOCK_METHOD0(exit, void());
        MOCK_METHOD0(tick, void());
};

class StateApplicationTest : public ::testing::Test {
    public:
        StateApplicationTest() {
            EXPECT_CALL(stateApplication, tick())
                .Times(AnyNumber());

            ON_CALL(stateApplication, tick())
                .WillByDefault(Invoke([&](){
                    stateApplication.getState()->tick();
                }));
        }
        virtual ~StateApplicationTest() {}

        MockStateApplication stateApplication;
};

TEST_F(StateApplicationTest, SetState) {
    mxg::application::DefaultState state;
    stateApplication.setState(state);
    ASSERT_EQ(stateApplication.getState(), &state);
}

TEST_F(StateApplicationTest, DontThrowErrorWhenNullState) {
    stateApplication.tick();
}

TEST_F(StateApplicationTest, OnSetStateCallEnter) {
    MockState state;

    EXPECT_CALL(state, enter())
        .Times(1);

    stateApplication.setState(state);
}

TEST_F(StateApplicationTest, OnSetStateCallExitAndThenEnterWhenStateIsNotNull) {
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

    stateApplication.setState(firstState);
    stateApplication.setState(secondState);
}

TEST_F(StateApplicationTest, RunStateApplication) {
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
            stateApplication.exit();
        }));

    stateApplication.setState(state);
    EXPECT_EQ(stateApplication.run(), 0);
}
