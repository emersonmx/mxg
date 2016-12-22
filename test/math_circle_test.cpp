#include "gtest/gtest.h"

#include "mxg/math/Utils.hpp"
#include "mxg/math/Circle.hpp"

using namespace mxg::math;

TEST(MathCircleTest, UseCircle) {
    Circle<int> c1;

    ASSERT_FLOAT_EQ(0, c1.x);
    ASSERT_FLOAT_EQ(0, c1.y);
    ASSERT_FLOAT_EQ(0, c1.radius);

    Circle<int> c2{10, 20, 100};

    ASSERT_FLOAT_EQ(10, c2.x);
    ASSERT_FLOAT_EQ(20, c2.y);
    ASSERT_FLOAT_EQ(100, c2.radius);
}

TEST(MathCircleTest, ContainCircles) {
    Circle<int> c1{10, 10, 10};
    Circle<int> c2{10, 10, 5};
    Circle<int> c3{10, 10, 20};

    ASSERT_TRUE(c1.contains(5, 5));
    ASSERT_TRUE(c1.contains(c2));
    ASSERT_FALSE(c1.contains(c3));
    ASSERT_TRUE(c3.contains(c1));
}

TEST(MathCircleTest, OverlapCircles) {
    Circle<int> c1{0, 0, 10};
    Circle<int> c2{15, 0, 10};
    Circle<int> c3{20, 0, 10};
    Circle<int> c4{0, 0, 5};
    Circle<int> c5{0, 0, 20};

    ASSERT_TRUE(c1.overlaps(c2));
    ASSERT_FALSE(c1.overlaps(c3));
    ASSERT_TRUE(c1.overlaps(c4));
    ASSERT_TRUE(c1.overlaps(c5));
}

TEST(MathCircleTest, GetCircleProperties) {
    Circle<float> c{0, 0, 10};
    float expectedArea = 10*10*utils::PI;
    float expectedCircumference = 10*utils::PI2;

    ASSERT_FLOAT_EQ(expectedArea, c.getArea());
    ASSERT_FLOAT_EQ(expectedCircumference, c.getCircumference());
}

TEST(MathCircleTest, UseCircleOperatos) {
    Circle<int> c1{0, 0, 10};
    Circle<int> c2{0, 0, 10};
    Circle<int> c3{10, 0, 10};

    ASSERT_EQ(c2, c1);
    ASSERT_NE(c3, c1);
}
