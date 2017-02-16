#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "mxg/Application.hpp"

using ::testing::AtMost;
using ::testing::Invoke;
using ::testing::Sequence;
using ::testing::Return;

class MockApplication : public mxg::Application {
    public:
        MOCK_METHOD0(create, void());
        MOCK_METHOD0(destroy, void());
        MOCK_METHOD0(tick, void());
};

class ApplicationTest : public ::testing::Test {
    public:
        ApplicationTest() {
            Sequence mainLoop;
            EXPECT_CALL(app, create())
                .Times(1)
                .InSequence(mainLoop);

            EXPECT_CALL(app, tick())
                .Times(AtMost(10))
                .InSequence(mainLoop);

            EXPECT_CALL(app, destroy())
                .Times(1)
                .InSequence(mainLoop);

            ON_CALL(app, tick())
                .WillByDefault(Invoke([&](){
                    app.exit();
                }));
        }
        virtual ~ApplicationTest() {}

        MockApplication app;
};

TEST_F(ApplicationTest, RunApplicationSuccessfully) {
    EXPECT_EQ(app.run(), 0);
}

TEST_F(ApplicationTest, ExitSuccessfullyInCreate) {
    ON_CALL(app, create()).WillByDefault(Invoke([&](){
        app.exit();
    }));
    EXPECT_EQ(app.run(), 0);
}

TEST_F(ApplicationTest, ExitWithErrorInCreate) {
    ON_CALL(app, create()).WillByDefault(Invoke([&](){
        app.exit(1);
    }));
    EXPECT_EQ(app.run(), 1);
}

TEST_F(ApplicationTest, ExitSuccessfullyInTick) {
    ON_CALL(app, tick()).WillByDefault(Invoke([&](){
        app.exit(0);
    }));
    EXPECT_EQ(app.run(), 0);
}

TEST_F(ApplicationTest, ExitWithErrorInTick) {
    ON_CALL(app, tick()).WillByDefault(Invoke([&](){
        app.exit(1);
    }));
    EXPECT_EQ(app.run(), 1);
}

TEST_F(ApplicationTest, ExitSuccessfullyInDestroy) {
    ON_CALL(app, tick()).WillByDefault(Invoke([&](){
        app.exit(0);
    }));
    EXPECT_EQ(app.run(), 0);
}

TEST_F(ApplicationTest, ExitWithErrorInDestroy) {
    ON_CALL(app, tick()).WillByDefault(Invoke([&](){
        app.exit(1);
    }));
    EXPECT_EQ(app.run(), 1);
}
