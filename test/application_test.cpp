#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "mxg/app/Application.hpp"

using ::testing::AtMost;
using ::testing::Invoke;
using ::testing::Sequence;
using ::testing::Return;

class MockApplication : public mxg::app::Application {
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

TEST_F(ApplicationTest, RunOk) {
    EXPECT_EQ(app.run(), 0);
}

TEST_F(ApplicationTest, RunHasError) {
    int errorCode = 1;
    ON_CALL(app, tick()).WillByDefault(Invoke([&](){
        app.exit(errorCode);
    }));
    EXPECT_EQ(app.run(), errorCode);
}

TEST_F(ApplicationTest, SkipMainLoop) {
    ON_CALL(app, create()).WillByDefault(Invoke([&](){
        app.exit();
    }));
    EXPECT_EQ(app.run(), 0);
}

TEST_F(ApplicationTest, SkipMainLoopWithError) {
    int errorCode = 1;
    ON_CALL(app, create()).WillByDefault(Invoke([&](){
        app.exit(errorCode);
    }));
    EXPECT_EQ(app.run(), errorCode);
}
