#include <catch.hpp>

#include <mxg/Size.hpp>
#include <mxg/Vector2.hpp>

TEST_CASE("Vector2 can be created", "[vector2]") {
    SECTION("creating without arguments results in origin vector") {
        mxg::Vector2 v;
        REQUIRE(v.x == Approx(0.0f).epsilon(0.01));
        REQUIRE(v.y == Approx(0.0f).epsilon(0.01));
    }
    SECTION("creating with arguments results in custom vector") {
        mxg::Vector2 v{1.0f, 2.0f};
        REQUIRE(v.x == Approx(1.0f).epsilon(0.01));
        REQUIRE(v.y == Approx(2.0f).epsilon(0.01));
    }
}

TEST_CASE("Vector2 can be compared", "[vector2]") {
    SECTION("comparing with operator == and equal vectors results in true") {
        mxg::Vector2 a;
        mxg::Vector2 b;
        REQUIRE(a == b);
    }
    SECTION("comparing with operator == and different vectors results in false") {
        mxg::Vector2 a;
        mxg::Vector2 b{1, 2};
        REQUIRE_FALSE(a == b);
    }

    SECTION("comparing with operator != and equal vectors results in false") {
        mxg::Vector2 a;
        mxg::Vector2 b;
        REQUIRE_FALSE(a != b);
    }
    SECTION("comparing with operator != and different vectors results in true") {
        mxg::Vector2 a;
        mxg::Vector2 b{1, 2};
        REQUIRE(a != b);
    }
}

TEST_CASE("Vector2 can be manipulated", "[vector2]") {
    SECTION("adding two vectors results in a new one with values added") {
        mxg::Vector2 a{1, 1};
        mxg::Vector2 b{2, 2};
        mxg::Vector2 c{-2, -2};
        REQUIRE(a + b == mxg::Vector2{3, 3});
        REQUIRE(a + c == mxg::Vector2{-1, -1});
    }
    SECTION("adding to a vector changes its values") {
        mxg::Vector2 a{1, 1};
        a += mxg::Vector2{3, 3};
        REQUIRE(a == mxg::Vector2{4, 4});
    }
    SECTION("subtracting two vectors results in a new one with values subtracted") {
        mxg::Vector2 a{1, 1};
        mxg::Vector2 b{2, 2};
        mxg::Vector2 c{-2, -2};
        REQUIRE(a - b == mxg::Vector2{-1, -1});
        REQUIRE(a - c == mxg::Vector2{3, 3});
    }
    SECTION("subtracting to a vector changes its values") {
        mxg::Vector2 a{1, 1};
        a -= mxg::Vector2{3, 3};
        REQUIRE(a == mxg::Vector2{-2, -2});
    }
    SECTION("negating a vector results in a new one with inverted value") {
        mxg::Vector2 a{1, 1};
        REQUIRE(-a == mxg::Vector2{-1, -1});
    }
    SECTION("multiplying a vector by a scalar results in a new one with values scalated") {
        mxg::Vector2 a{1, 1};
        mxg::Vector2 result{2, 2};
        REQUIRE(a * 2 == result);
        REQUIRE(2 * a == result);
    }
    SECTION("multiplying to a vector changes its values") {
        mxg::Vector2 a{1, 1};
        a *= 3;
        REQUIRE(a == mxg::Vector2{3, 3});
    }
    SECTION("dividing a vector by a scalar results in a new one with values divided") {
        mxg::Vector2 a{2, 2};
        mxg::Vector2 result{1, 1};
        REQUIRE(a / 2 == result);
    }
    SECTION("dividing to a vector changes its values") {
        mxg::Vector2 a{2, 2};
        a /= 2;
        REQUIRE(a == mxg::Vector2{1, 1});
    }
}

TEST_CASE("Vector2 can work with Size", "[size][vector2]") {
    mxg::Vector2 a{10, 10};
    mxg::Size s{32, 32};
    mxg::Vector2 result{26, 26};
    REQUIRE((a + s / 2) == result);
}
