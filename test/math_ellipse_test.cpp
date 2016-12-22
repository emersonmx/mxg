#include "gtest/gtest.h"

#include <iostream>

#include "mxg/math/Utils.hpp"
#include "mxg/math/Ellipse.hpp"

using namespace mxg::math;

TEST(MathEllipseTest, UseEllipse) {
    Ellipse<int> c1;

    ASSERT_FLOAT_EQ(0, c1.x);
    ASSERT_FLOAT_EQ(0, c1.y);
    ASSERT_FLOAT_EQ(0, c1.width);
    ASSERT_FLOAT_EQ(0, c1.height);

    Ellipse<int> c2{10, 20, 100, 200};

    ASSERT_FLOAT_EQ(10, c2.x);
    ASSERT_FLOAT_EQ(20, c2.y);
    ASSERT_FLOAT_EQ(100, c2.width);
    ASSERT_FLOAT_EQ(200, c2.height);

    Ellipse<int> c3;
    c3.set(1, 2, 3, 4);

    ASSERT_FLOAT_EQ(1, c3.x);
    ASSERT_FLOAT_EQ(2, c3.y);
    ASSERT_FLOAT_EQ(3, c3.width);
    ASSERT_FLOAT_EQ(4, c3.height);

    Ellipse<int> c4;
    c4.setPosition(1, 2);
    c4.setSize(4, 5);

    ASSERT_FLOAT_EQ(1, c4.x);
    ASSERT_FLOAT_EQ(2, c4.y);
    ASSERT_FLOAT_EQ(4, c4.width);
    ASSERT_FLOAT_EQ(5, c4.height);
}

TEST(MathEllipseTest, ContainEllipses) {
    Ellipse<float> c{0, 0, 20, 10};

    ASSERT_TRUE(c.contains(5, 0));
    ASSERT_FALSE(c.contains(0, 20));
}

TEST(MathEllipseTest, GetEllipseProperties) {
    Ellipse<float> c{0, 0, 10, 20};
    float expectedArea = 157.07964f;
    float expectedCircumference = 48.4421f;

    ASSERT_FLOAT_EQ(expectedArea, c.area());
    ASSERT_FLOAT_EQ(expectedCircumference, c.circumference());
}

TEST(MathEllipseTest, UseEllipseOperatos) {
    Ellipse<int> c1{0, 0, 10, 20};
    Ellipse<int> c2{0, 0, 10, 20};
    Ellipse<int> c3{10, 0, 10, 20};

    ASSERT_EQ(c2, c1);
    ASSERT_NE(c3, c1);
}
