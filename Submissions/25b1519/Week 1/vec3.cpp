#include <iostream>
#include <cmath>
using namespace std;

class Vec3 {
    public:
        float x, y, z;

    Vec3(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }

 Vec3 operator+(const Vec3& other) const {
    return Vec3(x + other.x, y + other.y, z + other.z);
 }

 Vec3 operator-(const Vec3& other) const {
        return Vec3(x - other.x, y - other.y, z - other.z);
 }

 Vec3 operator*(float k) const {
        return Vec3(x * k, y * k, z * k);
 }

 Vec3 operator/(float k) const {
        return Vec3(x / k, y / k, z / k);
 }

 Vec3 operator-() const {
        return Vec3(-x, -y, -z);
 }

 float operator[](int i) const {
        if (i == 0) return x;
        else if (i == 1) return y;
        else return z;
 }

 float length() const {
        return sqrt(x*x + y*y + z*z);
 }

 Vec3 unit() const {
        return (*this)/length();
 }

 float dot(const Vec3& other) const {
        return x*other.x + y*other.y + z*other.z;
 }

 Vec3 cross(const Vec3& other) const {
    return Vec3(y*other.z - z*other.y, z*other.x - x*other.z, x*other.y - y*other.x);
 }
 
 Vec3 reflect(const Vec3& normal) const {
        return (*this) - normal * (2 * this->dot(normal));
 }

};

int main() {
    Vec3 a(1, 2, 3);
    Vec3 b(4, 5, 6);

    Vec3 add = a + b;
    cout << "Addition: "
         << add.x << " " << add.y << " " << add.z << endl;

    Vec3 sub = a - b;
    cout << "Subtraction: "
         << sub.x << " " << sub.y << " " << sub.z << endl;

    Vec3 mul = a * 2;
    cout << "Multiply by 2: "
         << mul.x << " " << mul.y << " " << mul.z << endl;

    Vec3 div = a / 2;
    cout << "Divide by 2: "
         << div.x << " " << div.y << " " << div.z << endl;

    Vec3 neg = -a;
    cout << "Negation: "
         << neg.x << " " << neg.y << " " << neg.z << endl;

    cout << "Indexing a[0], a[1], a[2]: "
         << a[0] << " " << a[1] << " " << a[2] << endl;

    cout << "Length of a: "
         << a.length() << endl;

    Vec3 u = a.unit();
    cout << "Unit vector of a: "
         << u.x << " " << u.y << " " << u.z << endl;

    cout << "Dot product (a·b): "
         << a.dot(b) << endl;

    Vec3 cross = a.cross(b);
    cout << "Cross product (a x b): "
         << cross.x << " " << cross.y << " " << cross.z << endl;

    Vec3 normal(0, 1, 0);
    Vec3 refl = a.reflect(normal);
    cout << "Reflection of a about y-axis normal: "
         << refl.x << " " << refl.y << " " << refl.z << endl;

    return 0;
}