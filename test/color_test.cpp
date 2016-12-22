#include "gtest/gtest.h"

#include "mxg/graphics/Color.hpp"

using namespace mxg::graphics;

TEST(GraphicsColorTest, CreateColor) {
    Color c{};

    ASSERT_EQ(Color::Black, c);
}

TEST(GraphicsColorTest, AssignColors) {
    Color red = Color::Red;
    ASSERT_EQ(Color::Red, red);

    Color expectedGray{128, 128, 128};
    Color gray{128, 128, 128};
    ASSERT_EQ(expectedGray, gray);

    // RGBA: [220, 20, 60, 255]
    Color crimson{0xDC143CFF};
    ASSERT_EQ(220, crimson.r);
    ASSERT_EQ(20, crimson.g);
    ASSERT_EQ(60, crimson.b);
    ASSERT_EQ(255, crimson.a);
}

TEST(GraphicsColorTest, CompareColors) {
    Color crimson{0xDC143CFF};
    Color first = crimson;
    Color indigo{0x4B0082FF};
    Color gray{32, 32, 32};
    Color expected{};
    Color aux{};

    ASSERT_EQ(first, crimson);
    ASSERT_NE(indigo, crimson);

    expected = Color{0xFC345CFF};
    ASSERT_EQ(expected, crimson + gray);

    expected = Color{0xBC001C00};
    ASSERT_EQ(expected, crimson - gray);

    expected = Color{0x1B0207FF};
    ASSERT_EQ(expected, crimson * gray);

    aux = crimson;
    aux += gray;
    expected = Color{0xFC345CFF};
    ASSERT_EQ(expected, aux);

    aux = crimson;
    aux -= gray;
    expected = Color{0xBC001C00};
    ASSERT_EQ(expected, aux);

    aux = crimson;
    aux *= gray;
    expected = Color{0x1B0207FF};
    ASSERT_EQ(expected, aux);
}
