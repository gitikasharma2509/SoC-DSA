#ifndef VEC3_H
#define VEC3_H

#include <cmath>

using namespace std;

class Vec3 {
public:
    float x, y, z;

    Vec3(float x = 0, float y = 0, float z = 0)
        : x(x), y(y), z(z) {}

    Vec3 operator+(const Vec3& other) const {
        return Vec3(x + other.x, y + other.y, z + other.z);
    }

    Vec3 operator-(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
    }

    Vec3 operator*(float scalar) const {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    Vec3 operator/(float scalar) const {
        return Vec3(x / scalar, y / scalar, z / scalar);
    }

    Vec3 operator-() const {
        return Vec3(-x, -y, -z);
    }

    float& operator[](int i) {
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }

    float length() const {
        return sqrt(x*x + y*y + z*z);
    }

    Vec3 unit() const {
        float len = length();
        if (len == 0) return Vec3(0,0,0);
        return (*this) / len;
    }

    float dot(const Vec3& other) const {
        return x*other.x + y*other.y + z*other.z;
    }

    Vec3 cross(const Vec3& other) const {
        return Vec3(
            y*other.z - z*other.y,
            z*other.x - x*other.z,
            x*other.y - y*other.x
        );
    }

    Vec3 reflect(const Vec3& normal) const {
        return (*this) - normal * (2.0f * dot(normal));
    }

    Vec3 refract(const Vec3& normal, float refractive_index) const {
    Vec3 i = unit();
    Vec3 n = normal.unit();

    float cosi = -n.dot(i);

    float k = 1.0f - refractive_index * refractive_index * (1.0f - cosi * cosi);

    if (k < 0)
        return Vec3(0, 0, 0);

    return i * refractive_index +
           n * (refractive_index * cosi - sqrt(k));
    }

    friend Vec3 operator*(float scalar, const Vec3& v) {
        return v * scalar;
    }
};

#endif