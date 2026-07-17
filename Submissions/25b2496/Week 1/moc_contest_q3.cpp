#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

auto fgcd = [](double a, double b)
{
    while (b > 1e-9)
    {
        double t = fmod(a, b);
        a = b;
        b = t;
    }
    return a;
};

int main()
{
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    double s1 = x1 * x1 + y1 * y1;
    double s2 = x2 * x2 + y2 * y2;
    double s3 = x3 * x3 + y3 * y3;

    double denom = 2.0f * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));

    double Cir_X = (s1 * (y2 - y3) + s2 * (y3 - y1) + s3 * (y1 - y2)) / denom;
    double Cir_Y = (s1 * (x3 - x2) + s2 * (x1 - x3) + s3 * (x2 - x1)) / denom;

    double pi = acos(-1);

    double v1x = x1 - Cir_X;
    double v1y = y1 - Cir_Y;
    double v2x = x2 - Cir_X;
    double v2y = y2 - Cir_Y;
    double v3x = x3 - Cir_X;
    double v3y = y3 - Cir_Y;

    double magni1 = v1x * v1x + v1y * v1y; // square of the circumRadius

    double a1 = atan2(v1y, v1x);
    double a2 = atan2(v2y, v2x);
    double a3 = atan2(v3y, v3x);

    double angles[3] = {a1, a2, a3};
    sort(angles, angles + 3);

    double theta1 = angles[1] - angles[0];
    double theta2 = angles[2] - angles[1];
    double theta3 = 2.0 * pi - (angles[2] - angles[0]);

    int best_n = 3;
    for (int n = 3; n <= 100; n++)
    {
        double unit = 2.0 * pi / n;
        int k1 = (int)round(theta1 / unit);
        int k2 = (int)round(theta2 / unit);
        int k3 = (int)round(theta3 / unit);
        if (k1 + k2 + k3 != n)
            continue; // must partition the circle
        double err = abs(theta1 - k1 * unit) + abs(theta2 - k2 * unit) + abs(theta3 - k3 * unit);
        if (err < 1e-4)
        {
            best_n = n;
            break; // first valid n = smallest n = minimum area
        }
    }

    double area = (best_n * magni1 * sin(2.0 * pi / best_n)) / 2.0;
    cout << fixed << setprecision(6);
    cout << area;
}
