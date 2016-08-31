#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "mxg/Application.hpp"

using ::testing::AnyNumber;
using ::testing::Invoke;
using ::testing::Sequence;

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
                .Times(AnyNumber())
                .InSequence(mainLoop);

            EXPECT_CALL(app_, destroy())
                .Times(1)
                .InSequence(mainLoop);
        }
        virtual ~ApplicationTest() {}

        MockApplication app_;
};

TEST_F(ApplicationTest, RunOk) { 
    ON_CALL(app_, tick()).WillByDefault(Invoke([&](){
        app_.exit();
    }));
    int result = app_.run();
    EXPECT_EQ(result, 0);
}

TEST_F(ApplicationTest, RunHasError) { 
    int errorCode = 1;
    ON_CALL(app_, tick()).WillByDefault(Invoke([&](){
        app_.exit(errorCode);
    }));
    int result = app_.run();
    EXPECT_EQ(result, errorCode);
}

TEST_F(ApplicationTest, SkipMainLoop) { 
    ON_CALL(app_, create()).WillByDefault(Invoke([&](){
        app_.exit();
    }));
    int result = app_.run();
    EXPECT_EQ(result, 0);
}

TEST_F(ApplicationTest, SkipMainLoopWithError) { 
    int errorCode = 1;
    ON_CALL(app_, create()).WillByDefault(Invoke([&](){
        app_.exit(errorCode);
    }));
    int result = app_.run();
    EXPECT_EQ(result, errorCode);
}
