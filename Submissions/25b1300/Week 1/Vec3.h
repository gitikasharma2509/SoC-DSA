#include <bits/stdc++.h>
using namespace std;

class Vec3 {
public:
    float x, y, z;
    Vec3(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z) {}
    Vec3 operator+(const Vec3& v) const {
        return Vec3(x + v.x, y + v.y, z + v.z);
    }

    Vec3 operator-(const Vec3& v) const {
        return Vec3(x - v.x, y - v.y, z - v.z);
    }

    Vec3 operator-() const {
        return Vec3(-x, -y, -z);
    }

    Vec3 operator*(float s) const {
        return Vec3(x * s, y * s, z * s);
    }

    Vec3 operator/(float s) const {
        return Vec3(x / s, y / s, z / s);
    }

    friend Vec3 operator*(float s, const Vec3& v) {
        return Vec3(v.x * s, v.y * s, v.z * s);
    }

    float& operator[](int i) {
        if (i == 0) return x;
        if (i == 1) return y;
        return z; 
    }

    const float& operator[](int i) const {
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }
    float length() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    Vec3 unit() const {
        float len = length();
        if (len == 0.0f) return *this; 
        return *this / len;
    }

    float dot(const Vec3& v) const {
        return (x * v.x) + (y * v.y) + (z * v.z);
    }

    Vec3 cross(const Vec3& v) const {
        return Vec3(
            y * v.z - z * v.y,
            z * v.x - x * v.z,
            x * v.y - y * v.x
        );
    }

    Vec3 reflect(const Vec3& normal) const {

        return *this - normal * (2.0f * this->dot(normal));
    }

    Vec3 refract(const Vec3& normal, float eta) const {

        float cos_theta_i = -this->dot(normal);
        float sin2_theta_i = 1.0f - cos_theta_i * cos_theta_i;
        float sin2_theta_t = eta * eta * sin2_theta_i;

        if (sin2_theta_t > 1.0f) {
            return Vec3(0.0f, 0.0f, 0.0f); 
        }

        float cos_theta_t = sqrt(1.0f - sin2_theta_t);
        
        return (*this * eta) + (normal * (eta * cos_theta_i - cos_theta_t));
    }
};