#include <catch.hpp>

#include <mxg/Transform.hpp>

bool matrix_equals(const float* a, const float* b) {
    bool result = true;
    for (int i = 0; i < 9; ++i) {
        result = result && (a[i] == Approx(b[i]).epsilon(0.001));
    }
    return result;
}

TEST_CASE("Transforms can be created", "[transform]") {
    SECTION("creating without arguments results in identity matrix") {
        mxg::Transform t;
        float expected[] = {
            1.f, 0.f, 0.f,
            0.f, 1.f, 0.f,
            0.f, 0.f, 1.f
        };
        auto result = t.getMatrix();

        REQUIRE(matrix_equals(result, expected));
    }
    SECTION("creating with arguments results in a custom matrix") {
        mxg::Transform t{
            1.f, 2.f, 3.f,
            4.f, 5.f, 6.f,
            7.f, 8.f, 9.f
        };
        float expected[] = {
            1.f, 2.f, 3.f,
            4.f, 5.f, 6.f,
            7.f, 8.f, 9.f
        };
        auto result = t.getMatrix();

        REQUIRE(matrix_equals(result, expected));
    }
}
