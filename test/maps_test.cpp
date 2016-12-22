#include "gtest/gtest.h"

#include "mxg/maps/Properties.hpp"

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
