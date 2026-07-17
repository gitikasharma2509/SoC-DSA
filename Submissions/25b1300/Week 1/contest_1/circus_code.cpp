#include <bits/stdc++.h>
using namespace std;

struct coordinate {
    long double x;
    long double y;
};
long double length(coordinate a, coordinate b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

long double find_gcd(long double angle1, long double angle2) {
    while (abs(angle2) > 0.001) { 
        long double temp = angle2;
        angle2 = fmod(angle1, angle2);
        angle1 = temp;
    }
    return angle1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<coordinate> c(3);
    const long double MY_PI = 3.1415926535897932384626433832795;
    for (int i = 0; i < 3; i++) {
        cin >> c[i].x >> c[i].y;
    }
    long double a = length(c[0], c[1]);
    long double b = length(c[1], c[2]);
    long double d = length(c[2], c[0]);
    long double s = (a + b + d) / 2.0;
    long double triangle_area = sqrt(s * (s - a) * (s - b) * (s - d));
    long double R = (a * b * d) / (4.0 * triangle_area);
    long double angle_a = acos(max((long double)-1.0, min((long double)1.0, 1.0 - (a * a) / (2.0 * R * R))));
    long double angle_b = acos(max((long double)-1.0, min((long double)1.0, 1.0 - (b * b) / (2.0 * R * R))));
    long double angle_d = 2.0 * MY_PI - (angle_a + angle_b);
    long double angle = find_gcd(angle_a, angle_b);
    angle = find_gcd(angle, angle_d);
    long double total_area = (MY_PI / angle) * (R * R) * sin(angle);
    cout << fixed << setprecision(6) << total_area << "\n";

    return 0;
}