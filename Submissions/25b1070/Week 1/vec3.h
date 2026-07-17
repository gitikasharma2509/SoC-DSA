#include<bits/stdc++.h>
using namespace std;
class Vec3{
    public:
        float x,y,z;
        Vec3(float a,float b,float c){
            x=a;
            y=b;
            z=c;
            // used a,b,c to differentiate better input with our x,y,z 
        }
        Vec3 operator+(const Vec3& v) const {
            Vec3 ans(x,y,z);
            ans.x+=v.x;
            ans.y+=v.y;
            ans.z+=v.z;
            return ans;
        }
        Vec3 operator-(const Vec3& v) const {
            Vec3 ans(x,y,z);
            ans.x-=v.x;
            ans.y-=v.y;
            ans.z-=v.z;
            return ans;
        }
        Vec3 operator*(float a) const {
            Vec3 ans(x,y,z);
            ans.x*=a;
            ans.y*=a;
            ans.z*=a;
            return ans;
        }
        Vec3 operator/(float a) const {
            Vec3 ans(x,y,z);
            ans.x/=a;
            ans.y/=a;
            ans.z/=a;
            return ans;
        }
        Vec3 operator-() const {
            Vec3 ans(x,y,z);
            ans.x*=-1;
            ans.y*=-1;
            ans.z*=-1;
            return ans;
        }
        float& operator[](int a)  {
            if(a==0) return this->x;
            if(a==1) return this->y;
            if(a==2) return this->z;
            throw std::out_of_range("Vec3 index out of range"); 
        }
        float length() const {
            return sqrt(x*x + y*y + z*z);
        }
        Vec3 unit() const {
            Vec3 ans(x,y,z);
            ans=ans/ans.length();
            return ans;
        }
        float dot(const Vec3& v) const {
            return x*v.x+y*v.y+z*v.z;
        }
        Vec3 cross(const Vec3& v) const {
            Vec3 ans(x,y,z);
            ans.x=y*v.z-z*v.y;
            ans.y=z*v.x-x*v.z;
            ans.z=x*v.y-y*v.x;
            return ans; 
        }
        Vec3 reflect(const Vec3& normal) const {
            Vec3 ans(x,y,z);
            return ans-normal*(2.0f*(ans.dot(normal))); 
        }
        Vec3 refract(const Vec3& normal, float ri) const {
            Vec3 ans(x,y,z);
            ans=ans.unit();
            Vec3 n=normal.unit();
            Vec3 null(0,0,0);
            float thetha1 = acos(abs(ans.dot(n)));
            if (sin(thetha1)*ri > 1 ) return null; 
            float thetha2 = asin(sin(thetha1)*ri);
            return (ans*ri+n*(cos(thetha1)*ri-cos(thetha2))).unit();
        }
};
Vec3 operator*(float a, const Vec3& v) { return v * a; }