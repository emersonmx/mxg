#include <catch.hpp>

#include <iostream>

#include <mxg/Vector2.hpp>
#include <mxg/Transform.hpp>

bool matrix_equals(const float* a, const float* b, double epsilon=0.001) {
    bool result = true;
    for (int i = 0; i < 16; ++i) {
        result = result && (a[i] == Approx(b[i]).epsilon(epsilon));
    }
    return result;
}

TEST_CASE("Transforms can be created", "[transform]") {
    SECTION("creating without arguments results in OpenGL identity matrix") {
        mxg::Transform t;
        float expected[] = {
            1.f, 0.f, 0.f, 0.0f,
            0.f, 1.f, 0.f, 0.0f,
            0.f, 0.f, 1.f, 0.0f,
            0.f, 0.f, 0.f, 1.0f
        };
        auto result = t.getMatrix();

        REQUIRE(matrix_equals(result, expected));
    }
    SECTION("creating with arguments results in an OpenGL matrix") {
        mxg::Transform t{
            1.f, 2.f, 3.f,
            4.f, 5.f, 6.f,
            7.f, 8.f, 9.f
        };
        float expected[] = {
            1.f,  4.f, 0.0f, 7.f,
            2.f,  5.f, 0.0f, 8.f,
            0.0f, 0.0f, 1.0f, 0.0f,
            3.f,  6.f, 0.0f, 9.f,
        };
        auto result = t.getMatrix();

        REQUIRE(matrix_equals(result, expected));
    }
}

TEST_CASE("Transforms can be compared", "[transform]") {
    SECTION("comparing with operator == and equal transforms results in true") {
        mxg::Transform a;
        mxg::Transform b;
        REQUIRE(a == b);
    }
    SECTION("comparing with operator == and different transforms results in false") {
        mxg::Transform a;
        mxg::Transform b{1, 2, 3, 4, 5, 6, 7, 8, 9};
        REQUIRE_FALSE(a == b);
    }

    SECTION("comparing with operator != and different transforms results in true") {
        mxg::Transform a;
        mxg::Transform b{1, 2, 3, 4, 5, 6, 7, 8, 9};
        REQUIRE(a != b);
    }
    SECTION("comparing with operator != and equal transforms results in false") {
        mxg::Transform a;
        mxg::Transform b;
        REQUIRE_FALSE(a != b);
    }
}

TEST_CASE("Transforms can be combined", "[transform]") {
    mxg::Transform a{1, 0, 3,
                     0, 1, 3,
                     0, 0, 1};
    mxg::Transform b{1, 0, 5,
                     0, 1, 5,
                     0, 0, 1};
    mxg::Transform result{1, 0, 8,
                          0, 1, 8,
                          0, 0, 1};

    REQUIRE(a.combine(b) == result);
    REQUIRE(a == result);

    a = {1, 0, 3,
        0, 1, 3,
        0, 0, 1};
    REQUIRE((a * b) == result);

    a = {1, 0, 3,
        0, 1, 3,
        0, 0, 1};
    a *= b;
    REQUIRE(a == result);
}

TEST_CASE("Transforms can be translated", "[transform]") {
    mxg::Transform a{1, 0, 3,
                     0, 1, 3,
                     0, 0, 1};
    mxg::Vector2 b{5, 5};
    mxg::Transform result{1, 0, 8,
                          0, 1, 8,
                          0, 0, 1};

    REQUIRE(a.translate(b) == result);
}

TEST_CASE("Transforms can be rotated", "[transform]") {
    mxg::Transform a;
    mxg::Transform result{0.8660254, -0.5,      0,
                          0.5,       0.8660254, 0,
                          0,         0,         1};

    a.rotate(0.523599);
    REQUIRE(matrix_equals(a.getMatrix(), result.getMatrix()));
}

TEST_CASE("Transforms can be scaled", "[transform]") {
    mxg::Transform a;
    mxg::Transform result{2, 0, 0,
                          0, 2, 0,
                          0, 0, 1};

    REQUIRE(a.scale({2, 2}) == result);
}

TEST_CASE("Transforms can be inverted", "[transform]") {
    SECTION("inverting an identity matrix results in an identity matrix") {
        mxg::Transform identity;
        REQUIRE(matrix_equals(identity.getInverse().getMatrix(), identity.getMatrix()));
    }
    SECTION("inverting a matrix results in inverted matrix") {
        mxg::Transform a{
            9,  3,  5,
        -6, -9,  7,
        -1, -8,  1
        };
        mxg::Transform result{
            0.0764228, -0.0699187,  0.107317,
            -0.00162602, 0.0227642, -0.15122,
            0.0634146,  0.112195,  -0.102439
        };

        REQUIRE(matrix_equals(a.getInverse().getMatrix(), result.getMatrix()));
    }
}
