#include "gtest/gtest.h"

#include "mxg/maps/Properties.hpp"
#include "mxg/maps/Object.hpp"
#include "mxg/maps/objects/Circle.hpp"

struct Color {
    int r, g, b;
};

struct Circle {
    int x, y, radius;
};

TEST(MapTest, UseProperties) {
    mxg::maps::Properties p {
        { "x", "42" },
        { "y", "24" }
    };

    ASSERT_EQ("42", p["x"]);
    ASSERT_EQ("24", p["y"]);

    p["bg"] = "image/bg.png";

    ASSERT_EQ("image/bg.png", p["bg"]);
}

TEST(MapTest, UseObject) {
    mxg::maps::Object<Color> o;
    o.name = "Test";
    o.opacity = 0.5f;
    o.properties["position"] = "128,64";
    o.color = { 32, 64, 128 };

    ASSERT_EQ("Test", o.name);
    ASSERT_FLOAT_EQ(0.5f, o.opacity);
    ASSERT_EQ("128,64", o.properties["position"]);
    ASSERT_EQ(32, o.color.r);
    ASSERT_EQ(64, o.color.g);
    ASSERT_EQ(128, o.color.b);
}

TEST(MapTest, UseCircleObject) {
    mxg::maps::objects::Circle<Color, Circle> c;

    c.circle.x = 32;
    c.circle.y = 64;
    c.circle.radius = 100;

    ASSERT_EQ(32, c.circle.x);
    ASSERT_EQ(64, c.circle.y);
    ASSERT_EQ(100, c.circle.radius);
}
