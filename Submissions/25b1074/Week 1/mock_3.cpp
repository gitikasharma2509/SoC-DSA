#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double PI = acos(-1);

struct Point {
    double x, y;
};

double distance(Point a, Point b){
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main() {

    Point coords[3];
    for (int i = 0; i < 3; i++){
        double x, y;
        cin >> x >> y;
        coords[i] = {x, y};
    }

    double distances[3];
    
    double d1 = distance(coords[0], coords[1]);
    double d2 = distance(coords[1], coords[2]);
    double d3 = distance(coords[0], coords[2]);

    distances[0] = d1;
    distances[1] = d2;
    distances[2] = d3;

    // triangle area
    double s = (d1 + d2 + d3) / 2.0;
    double triangleArea = sqrt(s * (s - d1) * (s - d2) * (s - d3));

    // circumradius
    double R = (d1 * d2 * d3) / (4.0 * triangleArea);

    // central angles
    double A = acos((d2*d2 + d3*d3 - d1*d1) / (2.0*d2*d3));
    double B = acos((d1*d1 + d3*d3 - d2*d2) / (2.0*d1*d3));
    double C = acos((d1*d1 + d2*d2 - d3*d3) / (2.0*d1*d2));

    double alpha = 2.0 * A;
    double beta  = 2.0 * B;
    double gamma = 2.0 * C;

    int n;

    for (n = 3; n <= 100; n++) {
        double ang = 2.0 * PI / n;

        bool ok = true;

        double k1 = alpha / ang;
        double k2 = beta  / ang;
        double k3 = gamma / ang;

        if (abs(k1 - round(k1)) > 1e-4) ok = false;
        if (abs(k2 - round(k2)) > 1e-4) ok = false;
        if (abs(k3 - round(k3)) > 1e-4) ok = false;

        if (ok) break;
    }

    double area = 0.5 * n * R * R * sin(2.0 * PI / n);

    cout << fixed << setprecision(6) << area << endl;

}