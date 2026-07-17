#ifndef VEC3_H
#define VEC3_H
#include<cmath>

class Vec3{
public :

float x,y,z;

Vec3(float a, float b, float c){
    x = a;
    y = b;
    z = c;
}

Vec3 operator+(const Vec3&other)const{
    Vec3 v((this->x + other.x), (this->y + other.y), (this->z + other.z));
    return v;
}

Vec3 operator-(const Vec3&other)const{
    Vec3 v((this->x - other.x), (this->y - other.y), (this->z - other.z));
    return v;
}

Vec3 operator*(float p) const{
    Vec3 v((this->x * p), (this->y * p), (this->z * p));
    return v;
}

Vec3 operator/(float p)const{
     Vec3 v((this->x / p), (this->y / p), (this->z / p));
    return v;
}

Vec3 operator-()const{
    Vec3 v((-(this->x)), (-(this->y)), (-(this->z)));
    return v;
}

float& operator[](int i){
    if(i == 0) return this->x;
    if(i == 1) return this->y;
    if(i == 2) return this->z;
    
}

float length()const{
    return sqrt(((x)*(x)) + ((y)*(y)) + ((z)*(z)));
}

Vec3 unit()const{
    Vec3 v(x/this->length(), y/this->length(), z/this->length());
    return v;
}

float dot(const Vec3 &other)const{
    return ((this->x*other.x) + (this->y*other.y) + (this->z*other.z));
}

Vec3 cross(const Vec3 &other)const{
    Vec3 v(((this->y*other.z) - (other.y*this->z)), ((other.x*this->z) - (this->x*other.z)), ((this->x*other.y) - (this->y*other.x)));
    return v;
}

Vec3 reflect(const Vec3& normal)const{
    float m = 2*(this->dot(normal));
    Vec3 v = normal * m;
    Vec3 n = *this - v;
    return n;
}

Vec3 refract(const Vec3& normal, float refractive_index)const{
    float m = this->dot(normal);
    float h = 1-((refractive_index*refractive_index)*(1-(m*m)));
    if(h < 0){
        Vec3 u(0,0,0);
        return u;
    }
    float p = sqrt(1-((refractive_index*refractive_index)*(1-(m*m))));
    Vec3 v = normal * p;
    Vec3 n = (*this - (normal * m)) * refractive_index;
    Vec3 r = n - v;
    return r;
}
};

Vec3 operator*(float p, const Vec3& v){
    return v * p;
}

#endif

