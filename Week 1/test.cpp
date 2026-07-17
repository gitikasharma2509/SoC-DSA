#include <iostream>
#include <cmath>
#include <string>
#include "vec3.h"

// --- Test harness ---

static int total  = 0;
static int passed = 0;

static bool approx(float a, float b, float eps = 1e-4f) {
    return std::fabs(a - b) < eps;
}

static bool approxVec(const Vec3& a, const Vec3& b, float eps = 1e-4f) {
    return approx(a.x, b.x, eps) && approx(a.y, b.y, eps) && approx(a.z, b.z, eps);
}

static void check(bool condition, const std::string& name) {
    ++total;
    if (condition) {
        ++passed;
        std::cout << "  [PASS] " << name << "\n";
    } else {
        std::cout << "  [FAIL] " << name << "\n";
    }
}

static void section(const std::string& name) {
    std::cout << "\n" << name << "\n" << std::string(name.size(), '-') << "\n";
}

// --- Test groups ---

void test_constructor() {
    section("Constructor");
    Vec3 v(1.0f, 2.0f, 3.0f);
    check(approx(v.x, 1.0f), "x component");
    check(approx(v.y, 2.0f), "y component");
    check(approx(v.z, 3.0f), "z component");

    Vec3 zero(0, 0, 0);
    check(approx(zero.x, 0) && approx(zero.y, 0) && approx(zero.z, 0), "zero vector");

    Vec3 neg(-1.5f, -2.5f, -3.5f);
    check(approx(neg.x, -1.5f), "negative x");
}

void test_addition() {
    section("operator+");
    Vec3 a(1, 2, 3), b(4, 5, 6);
    check(approxVec(a + b, {5, 7, 9}),         "basic add");
    check(approxVec(a + Vec3(0,0,0), a),        "add zero");
    check(approxVec(Vec3(-1,-2,-3) + a, {0,0,0}), "add negation gives zero");
    check(approxVec(a + b, b + a),              "commutativity");
}

void test_subtraction() {
    section("operator-  (binary)");
    Vec3 a(5, 7, 9), b(1, 2, 3);
    check(approxVec(a - b, {4, 5, 6}),   "basic subtract");
    check(approxVec(a - a, {0, 0, 0}),   "self-subtract gives zero");
    check(approxVec(a - Vec3(0,0,0), a), "subtract zero");
}

void test_unary_minus() {
    section("operator-  (unary)");
    Vec3 v(1, -2, 3);
    check(approxVec(-v, {-1, 2, -3}),       "negate mixed signs");
    check(approxVec(-Vec3(0,0,0), {0,0,0}), "negate zero");
    check(approxVec(-(-v), v),              "double negation");
}

void test_scalar_multiply() {
    section("operator*");
    Vec3 v(1, 2, 3);
    check(approxVec(v * 2.0f,    {2, 4, 6}),   "scale up");
    check(approxVec(v * 0.5f,    {0.5f, 1, 1.5f}), "scale down");
    check(approxVec(v * 0.0f,    {0, 0, 0}),   "scale by zero");
    check(approxVec(v * -1.0f,   {-1,-2,-3}),  "scale by -1");
    check(approxVec(v * 1.0f,    v),            "scale by 1 (identity)");
    check(approxVec(2.0f * v,    v * 2.0f),     "commutativity (free operator)");
}

void test_scalar_divide() {
    section("operator/");
    Vec3 v(4, 6, 8);
    check(approxVec(v / 2.0f, {2, 3, 4}),   "basic divide");
    check(approxVec(v / 1.0f, v),            "divide by 1");
    check(approxVec(v / -1.0f, {-4,-6,-8}), "divide by -1");
    check(approxVec(v / 0.5f, {8, 12, 16}), "divide by 0.5");
}

void test_index_operator() {
    section("operator[]");
    Vec3 v(10, 20, 30);
    check(approx(v[0], 10), "index 0 = x");
    check(approx(v[1], 20), "index 1 = y");
    check(approx(v[2], 30), "index 2 = z");

    Vec3 w(0, 0, 0);
    w[0] = 7; w[1] = 8; w[2] = 9;
    check(approx(w[0], 7) && approx(w[1], 8) && approx(w[2], 9), "mutable write via []");
}

void test_length() {
    section("length()");
    check(approx(Vec3(1, 0, 0).length(), 1.0f),            "unit x axis");
    check(approx(Vec3(0, 1, 0).length(), 1.0f),            "unit y axis");
    check(approx(Vec3(0, 0, 1).length(), 1.0f),            "unit z axis");
    check(approx(Vec3(0, 0, 0).length(), 0.0f),            "zero vector");
    check(approx(Vec3(3, 4, 0).length(), 5.0f),            "3-4-5 triangle");
    check(approx(Vec3(1, 1, 1).length(), std::sqrt(3.0f)), "sqrt(3)");
    check(approx(Vec3(-3,-4,0).length(), 5.0f),            "negative components");
}

void test_unit() {
    section("unit()");
    auto u1 = Vec3(3, 0, 0).unit();
    check(approxVec(u1, {1, 0, 0}),                   "align with x axis");

    auto u2 = Vec3(0, 5, 0).unit();
    check(approxVec(u2, {0, 1, 0}),                   "align with y axis");

    auto u3 = Vec3(1, 1, 1).unit();
    check(approx(u3.length(), 1.0f),                  "magnitude of unit vector is 1");

    auto u4 = Vec3(-3, 4, 0).unit();
    check(approx(u4.length(), 1.0f),                  "magnitude after unit (negative components)");

    // Already unit
    Vec3 already(1, 0, 0);
    check(approxVec(already.unit(), already),          "already unit vector unchanged");
}

void test_dot() {
    section("dot()");
    Vec3 a(1, 0, 0), b(0, 1, 0);
    check(approx(a.dot(b), 0.0f),                      "perpendicular vectors = 0");
    check(approx(a.dot(a), 1.0f),                      "unit self-dot = 1");
    check(approx(Vec3(1,2,3).dot(Vec3(4,5,6)), 32.0f), "general dot product");
    check(approx(Vec3(1,2,3).dot(Vec3(-1,-2,-3)), -14.0f), "antiparallel");
    check(approx(a.dot(b), b.dot(a)),                  "commutativity");
    check(approx(Vec3(0,0,0).dot(Vec3(1,2,3)), 0.0f),  "zero vector dot");
}

void test_cross() {
    section("cross()");
    Vec3 x(1,0,0), y(0,1,0), z(0,0,1);
    check(approxVec(x.cross(y), z),                    "x cross y = z");
    check(approxVec(y.cross(x), -z),                   "y cross x = -z");
    check(approxVec(y.cross(z), x),                    "y cross z = x");
    check(approxVec(z.cross(x), y),                    "z cross x = y");

    // Self-cross = zero
    check(approxVec(x.cross(x), {0,0,0}),              "self-cross = zero");

    // Result is perpendicular to both inputs
    Vec3 a(1,2,3), b(4,5,6);
    Vec3 c = a.cross(b);
    check(approx(c.dot(a), 0.0f),                      "cross result perp to a");
    check(approx(c.dot(b), 0.0f),                      "cross result perp to b");

    // Anti-commutativity
    check(approxVec(a.cross(b), -(b.cross(a))),        "anti-commutativity");
}

void test_reflect() {
    section("reflect()");
    // Ray going straight down, normal pointing up → straight up
    Vec3 down(0, -1, 0), up(0, 1, 0);
    check(approxVec(down.reflect(up), {0, 1, 0}),      "vertical reflection");

    // 45-degree incidence on a flat floor
    Vec3 v45(-1, -1, 0);
    Vec3 r45 = v45.reflect(up);
    check(approxVec(r45, {-1, 1, 0}),                  "45-degree reflection");

    // Reflecting an already-parallel-to-normal ray
    Vec3 straight(0, 1, 0);
    check(approxVec(straight.reflect(up), -1*straight),   "parallel to normal unchanged");

    // Length preserved
    Vec3 v(1, -2, 3);
    Vec3 n = Vec3(0, 1, 0);
    check(approx(v.reflect(n).length(), v.length()),   "reflection preserves length");
}

void test_refract() {
    section("refract()");
    // Straight-on ray through any medium: direction unchanged
    Vec3 straight(0, -1, 0);
    Vec3 normal(0, 1, 0);
    Vec3 r1 = straight.refract(normal, 1.0f);
    check(approxVec(r1, straight, 1e-3f),              "normal incidence, ri=1 unchanged");

    // ri=1 (same medium): direction preserved for oblique ray too
    Vec3 oblique = Vec3(1, -1, 0).unit();
    Vec3 r2 = oblique.refract(normal, 1.0f);
    check(approxVec(r2, oblique, 1e-3f),               "ri=1, oblique: direction preserved");

    // Snell's law: sin(theta_t) = ri * sin(theta_i)
    // theta_i = 30°, ri = 1/1.5 ≈ 0.6667 → theta_t ≈ 19.47°
    float theta_i = 30.0f * 3.14159265f / 180.0f;
    Vec3  incident = Vec3(std::sin(theta_i), -std::cos(theta_i), 0).unit();
    Vec3  refracted = incident.refract(normal, 1.0f / 1.5f);
    float sin_t = refracted.x;  // x-component encodes sin(theta_t)
    float expected_sin_t = (1.0f / 1.5f) * std::sin(theta_i);
    check(approx(sin_t, expected_sin_t, 1e-3f),        "Snell's law: sin ratio correct");

    // Total internal reflection: ri > 1 at steep angle
    Vec3 steep = Vec3(0.9f, -std::sqrt(1.0f - 0.81f), 0).unit();
    Vec3 tir   = steep.refract(normal, 1.5f);
    check(approxVec(tir, {0, 0, 0}),                   "total internal reflection → zero vector");

    // Refracted ray is unit length (when not TIR)
    check(approx(refracted.length(), 1.0f, 1e-3f),     "refracted ray is unit length");
}

// --- Entry point ---

int main() {
    std::cout << "Vec3 Test Suite\n" << std::string(40, '=') << "\n";

    test_constructor();
    test_addition();
    test_subtraction();
    test_unary_minus();
    test_scalar_multiply();
    test_scalar_divide();
    test_index_operator();
    test_length();
    test_unit();
    test_dot();
    test_cross();
    test_reflect();
    test_refract();

    std::cout << "\n" << std::string(40, '=') << "\n";
    std::cout << "Result: " << passed << " / " << total << " passed";
    int score = (total > 0) ? (passed * 100 / total) : 0;
    std::cout << "  |  Score: " << score << "/100\n";

    return (passed == total) ? 0 : 1;
}
