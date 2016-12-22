#include "gtest/gtest.h"

#include "mxg/math/Utils.hpp"
#include "mxg/math/Vector2.hpp"

using namespace mxg::math;

TEST(MathVector2Test, UseVector2) {
    Vector2i vec1;
    Vector2i vec2{10, 20};
    Vector2i vec3{30, 40};
    Vector2i vec4{vec3};
    Vector2i expected{10, 20};

    ASSERT_EQ(Vector2i{}, vec1);
    ASSERT_EQ(expected, vec2);
    ASSERT_EQ(vec3, vec4);
}

TEST(MathVector2Test, CheckVector2Operators) {
    Vector2f v{10, 10};
    Vector2f expected{-10, -10};

    ASSERT_EQ(expected, -v);

    v += {20, 20};
    expected = {30, 30};
    ASSERT_EQ(expected, v);

    v -= {15, 15};
    expected = {15, 15};
    ASSERT_EQ(expected, v);

    v = Vector2f{10, 10} + Vector2f{5, 5};
    ASSERT_EQ(expected, v);

    v = Vector2f{10, 10} - Vector2f{5, 5};
    expected = {5, 5};
    ASSERT_EQ(expected, v);

    v = Vector2f{1, 1} * 5.0f;
    ASSERT_EQ(expected, v);

    v = 5.0f * Vector2f{1, 1};
    ASSERT_EQ(expected, v);

    v = {1, 1};
    v *= 5.0f;
    ASSERT_EQ(expected, v);

    v = Vector2f{1, 1} / 2.0f;
    expected = {0.5f, 0.5f};
    ASSERT_EQ(expected, v);

    v = {1, 1};
    v /= 2.0f;
    ASSERT_EQ(expected, v);

    ASSERT_EQ(Vector2i(10, 10), Vector2i(10, 10));
    ASSERT_NE(Vector2i{}, Vector2i(10, 10));
}
