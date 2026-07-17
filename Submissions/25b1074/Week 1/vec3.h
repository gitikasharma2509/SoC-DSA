#ifndef VEC3_H
#define VEC3_H

class Vec3 {

    public:

    float x, y, z;

    Vec3(float a, float b, float c){
        x = a;
        y = b;
        z = c;
    }

    Vec3 operator+(const Vec3& v){
        return Vec3(x + v.x, y + v.y, z + v.z);
    }

    Vec3 operator-(const Vec3& v){
        return Vec3(x - v.x, y - v.y, z - v.z);
    }

    Vec3 operator*(float s){
        return Vec3(x * s, y * s, z * s);
    }

    Vec3 operator/(float s){
        return Vec3(x / s, y / s, z / s);
    }
    
    Vec3 operator-(){
        return Vec3(-x, -y, -z);
    }

    float& operator[](int i){
        if (i == 0) return x;
        else if (i == 1) return y;
        else if (i == 2) return z;
    }

    float length() const {
        return sqrt(x*x + y*y + z*z);
    }

    Vec3 unit() const {
        float len = length();
        return Vec3(x / len, y / len, z / len);
    }

    float dot(const Vec3& other) const{
        return x * other.x + y * other.y + z * other.z;
    }

    Vec3 cross(const Vec3& other){
        return Vec3{y*other.z - z*other.y, z*other.x - x*other.z, x*other.y - y*other.x};
    }

    Vec3 reflect(const Vec3& normal){
        return  *this - (normal.unit() * (this->dot(normal))) * 2 ;
    }

    Vec3 refract(const Vec3& normal, float refractive_index){
        Vec3 n = normal.unit();
        float cos_i = this->dot(n) / this->length();
        float sin_r = sqrt(1 - cos_i * cos_i) * refractive_index ;
        if (sin_r > 1) {
            return Vec3(0,0,0); // Total internal reflection, no refraction
        }
        else if (sin_r == 0) {
            //normal incidence
            return *this;
        }
        else{
            float cos_r = sqrt(1 - sin_r * sin_r);
            Vec3 v = (*this - n * (this->dot(n))) ; //along the surface
            Vec3 r =  - n * (v.length() * sqrt((1/sin_r)*(1/sin_r) - 1)); //perpendicular to the surface
            return (v + r).unit();
        }
    }
};

Vec3 operator*(float s, Vec3& v) {
    return v * s;
}

#endif