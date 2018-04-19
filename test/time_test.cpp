#include <catch.hpp>

#include <mxg/Time.hpp>

TEST_CASE("Create empty time", "[time]") {
    mxg::Time t;
    REQUIRE(t.asMicroseconds() == 0);
}

TEST_CASE("Create time in seconds", "[time]") {
    mxg::Time t = mxg::seconds(5.0f);
    REQUIRE(t.asSeconds() == 5.0f);
}

TEST_CASE("Create time in milliseconds", "[time]") {
    mxg::Time t = mxg::milliseconds(5000);
    REQUIRE(t.asMilliseconds() == 5000);
}

TEST_CASE("Create time in microseconds", "[time]") {
    mxg::Time t = mxg::microseconds(5000000L);
    REQUIRE(t.asMicroseconds() == 5000000L);
}

TEST_CASE("Time operators", "[time]") {
    SECTION("a == b") {
        mxg::Time a = mxg::milliseconds(1000);
        mxg::Time b = mxg::milliseconds(1000);

        REQUIRE(a == b);
    }
    SECTION("a != b") {
        mxg::Time a = mxg::milliseconds(1000);
        mxg::Time b = mxg::milliseconds(2000);

        REQUIRE(a != b);
    }
    SECTION("a < b") {
        mxg::Time a = mxg::milliseconds(1000);
        mxg::Time b = mxg::milliseconds(2000);

        REQUIRE(a < b);
    }
    SECTION("a > b") {
        mxg::Time a = mxg::milliseconds(2000);
        mxg::Time b = mxg::milliseconds(1000);

        REQUIRE(a > b);
    }
    SECTION("a <= b") {
        mxg::Time a = mxg::milliseconds(1000);
        mxg::Time b = mxg::milliseconds(2000);
        mxg::Time c = mxg::milliseconds(1000);

        REQUIRE(a <= b);
        REQUIRE(a <= c);
    }
    SECTION("a >= b") {
        mxg::Time a = mxg::milliseconds(2000);
        mxg::Time b = mxg::milliseconds(1000);
        mxg::Time c = mxg::milliseconds(2000);

        REQUIRE(a >= b);
        REQUIRE(a >= c);
    }
    SECTION("-a") {
        mxg::Time a = mxg::milliseconds(2000);
        mxg::Time b = mxg::milliseconds(-2000);

        REQUIRE(-a == b);
    }
    SECTION("a + b") {
        mxg::Time a = mxg::milliseconds(2000);
        mxg::Time b = mxg::milliseconds(1000);
        mxg::Time c = mxg::milliseconds(3000);

        REQUIRE((a + b) == c);
    }
    SECTION("a += b") {
        mxg::Time a = mxg::milliseconds(2000);
        mxg::Time b = mxg::milliseconds(1000);
        mxg::Time c = mxg::milliseconds(3000);
        a += b;

        REQUIRE(a == c);
    }
    SECTION("a - b") {
        mxg::Time a = mxg::milliseconds(2000);
        mxg::Time b = mxg::milliseconds(1000);
        mxg::Time c = mxg::milliseconds(1000);

        REQUIRE((a - b) == c);
        REQUIRE((b - a) == -c);
    }
    SECTION("a -= b") {
        mxg::Time a = mxg::milliseconds(2000);
        mxg::Time b = mxg::milliseconds(1000);
        mxg::Time c = mxg::milliseconds(1000);
        a -= b;

        REQUIRE(a == c);

        b -= mxg::milliseconds(2000);
        REQUIRE(b == -c);
    }
    SECTION("a * b") {
        mxg::Time a = mxg::milliseconds(100);
        mxg::Time c = mxg::milliseconds(100 * 100);

        REQUIRE((a * 100.f) == c);
        REQUIRE((100.f * a) == c);
        REQUIRE((a * 100L) == c);
        REQUIRE((100L * a) == c);
    }
    SECTION("a *= b") {
        mxg::Time a = mxg::milliseconds(100);
        mxg::Time c = mxg::milliseconds(100 * 100);
        a *= 100.f;
        REQUIRE(a == c);

        a = mxg::milliseconds(100);
        a *= 100L;
        REQUIRE(a == c);
    }
    SECTION("a / b") {
        mxg::Time a = mxg::milliseconds(100);
        mxg::Time b = mxg::milliseconds(2);
        mxg::Time c = mxg::milliseconds(50);

        REQUIRE((a / 2.f) == c);
        REQUIRE((a / 2L) == c);
        REQUIRE((a / b) == 100/2);
    }
    SECTION("a /= b") {
        mxg::Time a = mxg::milliseconds(100);
        mxg::Time c = mxg::milliseconds(50);
        a /= 2.f;
        REQUIRE(a == c);

        a = mxg::milliseconds(100);
        a /= 2L;
        REQUIRE(a == c);
    }
    SECTION("a %% b") {
        mxg::Time a = mxg::milliseconds(100);
        mxg::Time b = mxg::milliseconds(200);
        mxg::Time c = mxg::milliseconds(100 % 200);
        REQUIRE((a % b) == c);
    }
    SECTION("a %%= b") {
        mxg::Time a = mxg::milliseconds(100);
        mxg::Time b = mxg::milliseconds(200);
        mxg::Time c = mxg::milliseconds(100 % 200);
        a %= b;
        REQUIRE(a == c);
    }
}
