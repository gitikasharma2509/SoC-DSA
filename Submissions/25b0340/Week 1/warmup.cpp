#include <cmath>
#include <stdexcept>

class Vec3 {
public:
    float x, y, z;
    Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

    // componentwise addition
    Vec3 operator+(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    // componentwise subtraction
    Vec3 operator-(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }

    // Scalar multiplication
    Vec3 operator*(float scalar) const {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    // Scalar division
    Vec3 operator/(float scalar) const {
        return Vec3(x / scalar, y / scalar, z / scalar);
    }

    // Unary minus
    Vec3 operator-() const {
        return Vec3(-x, -y, -z);
    }

    // Index operator
    float& operator[](int i) {
        if (i == 0) return x;
        if (i == 1) return y;
        if (i == 2) return z;
        throw std::out_of_range("Index out of range");
    }

    const float& operator[](int i) const {
        if (i == 0) return x;
        if (i == 1) return y;
        if (i == 2) return z;
        throw std::out_of_range("Index out of range");
    }

    // Euclidean length
    float length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    // unit vector
    Vec3 unit() const {
        float len = length();
        return (*this) / len;
    }

    // dot product
    float dot(const Vec3& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // cross product
    Vec3 cross(const Vec3& other) const {
        return Vec3(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }

    // Reflection
    Vec3 reflect(const Vec3& n) const {
        return (*this) - n * (2.0f * this->dot(n));
    }

    // Refraction using Snells law
    Vec3 refract(const Vec3& n, float ri) const {
        Vec3 uv = this->unit();

        float cos_theta = fmin((-uv).dot(n), 1.0f);

        Vec3 r_out_perp =
            (uv + n * cos_theta) * ri;

        float k = 1.0f - r_out_perp.dot(r_out_perp);

        Vec3 r_out_parallel =
            n * (-std::sqrt(std::fabs(k)));

        return r_out_perp + r_out_parallel;
    }
};