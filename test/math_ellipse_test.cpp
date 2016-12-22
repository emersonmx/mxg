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

    ASSERT_FLOAT_EQ(expectedArea, c.getArea());
    ASSERT_FLOAT_EQ(expectedCircumference, c.getCircumference());
}

TEST(MathEllipseTest, UseEllipseOperatos) {
    Ellipse<int> c1{0, 0, 10, 20};
    Ellipse<int> c2{0, 0, 10, 20};
    Ellipse<int> c3{10, 0, 10, 20};

    ASSERT_EQ(c2, c1);
    ASSERT_NE(c3, c1);
}
