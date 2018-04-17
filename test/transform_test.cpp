#include <catch.hpp>

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
}

TEST_CASE("Transforms can be translated", "[transform]") {
}

TEST_CASE("Transforms can be rotated", "[transform]") {
}

TEST_CASE("Transforms can be scaled", "[transform]") {
}

TEST_CASE("Transforms can be inverted", "[transform]") {
}
