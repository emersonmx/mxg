#include "gtest/gtest.h"

#include "mxg/math/Rectangle.hpp"

using namespace mxg::math;

TEST(MathRectangleTest, UseRectangle) {
    RectangleInt r;
    RectangleInt expected{1, 2, 3, 4};

    ASSERT_EQ(RectangleInt{}, r);

    r = {1, 2, 3, 4};
    ASSERT_EQ(expected, r);

    r = RectangleInt({1, 2}, {3, 4});
    ASSERT_EQ(expected, r);

    r = RectangleInt({1, 2, 3, 4});
    ASSERT_EQ(expected, r);
}

TEST(MathRectangleTest, ContainsRectangle) {
    RectangleInt r1{0, 0, 10, 10};

    ASSERT_TRUE(r1.contains(5, 5));
    ASSERT_TRUE(r1.contains({2, 2}));
}

TEST(MathRectangleTest, IntersectsRectangle) {
    RectangleInt r1{0, 0, 10, 10};
    RectangleInt r2{5, 5, 10, 10};
    RectangleInt r3{30, 30, 10, 10};

    ASSERT_TRUE(r1.intersects(r1));
    ASSERT_TRUE(r1.intersects(r2));
    ASSERT_FALSE(r1.intersects(r3));
}
