#ifndef VEC3_H
#define VEC3_H
#include <cmath>
class Vec3{
    public:
        float x,y,z;
    
    Vec3(float x,float y,float z) : x(x), y(y), z(z) {}

    Vec3 operator+(const Vec3& v) const {
        return Vec3(x + v.x,y + v.y,z + v.z);
    }

    Vec3 operator-(const Vec3& v) const {
        return Vec3(x - v.x,y - v.y,z - v.z);
    }

    Vec3 operator*(float a) const{
        return Vec3(x * a,y * a,z * a);
    }

    Vec3 operator/(float a) const{
        return Vec3(x / a,y / a,z / a);
    }

    Vec3 operator-() const{
        return Vec3(-x,-y,-z);
    }

    float& operator[](int i) {
        if (i == 0) return x;
        if (i == 1) return y;
        return z;
    }

    float length() const {
        return std::sqrt(x*x + y*y + z*z);
    }

    Vec3 unit() const {
        float len = length();
        return Vec3(x / len,y / len,z / len);
    }

    float dot(const Vec3& v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    Vec3 cross(const Vec3& v) const {
        return Vec3(y * v.z - z * v.y,z * v.x - x * v.z,x * v.y - y * v.x);
    }

    Vec3 reflect(const Vec3& normal) const {
        return *this - normal * (2.0f * this->dot(normal));
    }

    Vec3 refract(const Vec3& normal, float refractive_index) const {
        Vec3 uv = unit();
        float cos_theta = (-uv).dot(normal);
        float discriminant = 1.0f - refractive_index * refractive_index * (1.0f - cos_theta * cos_theta);

    if (discriminant < 0.0f) {
        return Vec3(0, 0, 0);
    }

    Vec3 perpendicular =
        (uv + normal * cos_theta) * refractive_index;

    Vec3 parallel =
        normal * -std::sqrt(discriminant);

    return perpendicular + parallel;
    }
};
inline Vec3 operator*(float scalar, const Vec3& v) {
    return Vec3(
        v.x * scalar,
        v.y * scalar,
        v.z * scalar
    );
}
#endif