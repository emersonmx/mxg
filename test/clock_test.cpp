#include <catch.hpp>

#include <mxg/Clock.hpp>

TEST_CASE("Compare clocks", "[clock]") {
    mxg::Clock a;
    auto first = a.getElapsedTime();
    for (int i = 0; i < 10000; ++i);
    auto second = a.getElapsedTime();
    REQUIRE(first < second);
}

TEST_CASE("Restart clock", "[clock]") {
    mxg::Clock a;
    auto t0 = a.restart();
    REQUIRE(t0.asMicroseconds() >= 0);
    for (int i = 0; i < 10000; ++i);
    auto t = a.restart();
    REQUIRE(t.asMicroseconds() <= 1000);
}
