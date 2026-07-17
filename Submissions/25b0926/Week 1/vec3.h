#include <iostream>
#include <cmath>
using namespace std;

class Vec3 {
public:
    float x, y, z;
    Vec3(float x,float y,float z)
        : x(x), y(y), z(z){}
    
    Vec3 operator+(const Vec3& v){
        return Vec3(x + v.x, y + v.y, z + v.z);
    }
    Vec3 operator-(const Vec3& v){
        return Vec3(x - v.x, y - v.y, z - v.z);
    }
    Vec3 operator*(float k){
        return Vec3(x * k, y * k, z * k);
    }
    Vec3 operator/(float k){
        return Vec3(x / k, y / k, z / k);
    }
    Vec3 operator-(){
        return Vec3(-x,-y,-z);
    }
    float& operator[](int i){
        if (i == 0) return x;
        if (i == 1) return y;
        return z;

    }
    float length() const{
        return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    }
    Vec3 unit() const{
        return Vec3(x/length(),y/length(),z/length());
    }
    float dot(const Vec3& other){
        return (x*other.x+y*other.y+z*other.z);
    }
    Vec3 cross(const Vec3& other){
        return Vec3(y*other.z-z*other.y,z*other.x-x*other.z,x*other.y-y*other.x);
    }
    Vec3 reflect(const Vec3& normal){
        Vec3 n = normal.unit();
        return (*this- n*(*this).dot(n)*2);
    }
    Vec3 refract(const Vec3& normal,float refractive_index){
        Vec3 i= (*this).unit();
        Vec3 n= normal.unit();
        Vec3 surface_parallel=(i-n*i.dot(n))*refractive_index;
        Vec3 surface_perpendicular=-n*sqrt(1-surface_parallel.length()*surface_parallel.length());
        if(surface_parallel.length()>1)
            return Vec3(0,0,0);
        else
        return (surface_parallel+surface_perpendicular);
    }
};
Vec3 operator*(float k,Vec3 v){
    return Vec3(v.x * k, v.y * k, v.z * k);
}