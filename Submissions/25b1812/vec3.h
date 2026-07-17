#ifndef VEC3_H
#define VEC3_H
#include <cmath>

class Vec3{
public:
    float x;
    float y;
    float z;
    Vec3(float a, float b, float c){
        x = a;
        y = b;
        z = c;
    }
    Vec3 operator+(const Vec3& t)const{
        return Vec3(x + t.x, y + t.y , z + t.z);
    }
    Vec3 operator-(const Vec3& t)const{
        return Vec3(x - t.x, y - t.y , z - t.z);
    }
    Vec3 operator*(float n)const{
        return Vec3(n*x, n*y , n*z);
    }
    Vec3 operator/(float n)const{
        return Vec3(x/n, y/n, z/n);
    }
    Vec3 operator-()const{
        return Vec3(-x, -y, -z);
    }
    float& operator[](int i){
        if (i == 0) return x;
        else if (i == 1) return y;
        else return z;
    }
    const float& operator[](int i)const{
        if (i == 0) return x;
        else if (i == 1) return y;
        else return z;
    }
    float length()const{
        return sqrt(x*x + y*y + z*z);
    }
    Vec3 unit()const{
        return Vec3(x/length(), y/length(), z/length());
    }
    float dot(const Vec3& v)const{
        return (v.x*x + v.y*y + v.z*z);
    }
    Vec3 cross(const Vec3& v)const{
        return Vec3(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x);
    }
    Vec3 reflect(const Vec3& n)const{
        Vec3 unit_n = n.unit();
        return *this - unit_n * 2*(this->dot(unit_n));
    }
    Vec3 refract(const Vec3& normal, float eta)const{
        Vec3 unit_v = this->unit();
        Vec3 unit_n = normal.unit();
        float cos1 = -(unit_v.dot(unit_n));
        if (1 - (1/(eta*eta)) * (1 - cos1*cos1) >= 0){
        float cos2 = sqrt(1 - (1/(eta*eta)) * (1 - cos1*cos1));
        return unit_v * (1/eta) + unit_n * (cos1/eta - cos2);}
        else {
            return this->reflect(normal);
        }
    }
};

inline Vec3 operator*(float n, const Vec3& v){
    return v * n;
}

#endif