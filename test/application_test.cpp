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
    protected:
        ApplicationTest() {
            Sequence mainLoop;
            EXPECT_CALL(app_, create())
                .Times(1)
                .InSequence(mainLoop);

            EXPECT_CALL(app_, tick())
                .Times(AtMost(10))
                .InSequence(mainLoop)
                .WillOnce(Return())
                .WillOnce(Return());

            EXPECT_CALL(app_, destroy())
                .Times(1)
                .InSequence(mainLoop);

            ON_CALL(app_, tick())
                .WillByDefault(Invoke([&](){
                    app_.exit();
                }));
        }
        virtual ~ApplicationTest() {}

        MockApplication app_;
};

TEST_F(ApplicationTest, RunOk) {
    EXPECT_EQ(app_.run(), 0);
}

TEST_F(ApplicationTest, RunHasError) {
    int errorCode = 1;
    ON_CALL(app_, tick()).WillByDefault(Invoke([&](){
        app_.exit(errorCode);
    }));
    EXPECT_EQ(app_.run(), errorCode);
}

TEST_F(ApplicationTest, SkipMainLoop) {
    ON_CALL(app_, create()).WillByDefault(Invoke([&](){
        app_.exit();
    }));
    EXPECT_EQ(app_.run(), 0);
}

TEST_F(ApplicationTest, SkipMainLoopWithError) {
    int errorCode = 1;
    ON_CALL(app_, create()).WillByDefault(Invoke([&](){
        app_.exit(errorCode);
    }));
    EXPECT_EQ(app_.run(), errorCode);
}
