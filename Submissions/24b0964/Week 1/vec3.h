#include <iostream>
#include <cmath>
using namespace std;

class Vec3{ 
    public:
        float x, y, z;
        Vec3(float xt, float yt, float zt){
            x=xt; y=yt; z=zt;
        }

        Vec3 operator+(const Vec3& v){
            Vec3 res(x, y, z);
            res.x+= v.x; res.y+= v.y; res.z+= v.z;
            return res;
        }

        Vec3 operator-(const Vec3& v){
            Vec3 res(x, y, z);
            res.x-= v.x; res.y-= v.y; res.z-= v.z;
            return res;
        }

        Vec3 operator*(float f) const{
            Vec3 res(x, y, z);
            res.x*= f; res.y*= f; res.z*= f;
            return res;
        }

        friend Vec3 operator*(float s, const Vec3& v);

        

        Vec3 operator/(float f){
            Vec3 res(x, y, z);
            res.x/= f; res.y/= f; res.z/= f;
            return res;
        }

        Vec3 operator-(){
            Vec3 res(x, y, z);
            res.x= -x; res.y= -y; res.z= -z;
            return res;
        }

        float& operator[](int i){
            if(i==0) return x;
            if(i==1) return y;
            return z;
        }

        float length(){
            return sqrt((x*x) + (y*y) + (z*z));
        }

        Vec3 unit(){
            float l = length();
            return Vec3(x/l, y/l, z/l);
        }

        float dot(const Vec3& other){
            return (x*other.x) + (y*other.y) + (z*other.z);
        }

        Vec3 cross(const Vec3& other){
            return Vec3((y*other.z - z*other.y), (z*other.x - x*other.z), (x*other.y - y*other.x));
        }

        Vec3 reflect(const Vec3& normal){
            Vec3 v = Vec3(x, y, z);
            return v - (2*v.dot(normal))*normal;
        }

        Vec3 refract(const Vec3& normal, float refractive_index){
            Vec3 v = Vec3(x, y, z);
            float cos = - v.dot(normal);
            float term = 1-(refractive_index*refractive_index*(1-(cos*cos)));
            if(term >= 0) return (refractive_index*v) + ((refractive_index*cos) - sqrt(term))*normal;
            else return Vec3(0, 0, 0);
        }
};


inline Vec3 operator*(float s, const Vec3& v) {
    return v * s;
}