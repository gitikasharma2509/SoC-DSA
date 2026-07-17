#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;

const double EPS = 1e-9;

double X[3], Y[3], R[3];

int main() {
    for (int i = 0; i < 3; i++) {
        cin >> X[i] >> Y[i] >> R[i];
    }
    double a1 = 2.0 * (X[0] - X[1]);
    double b1 = 2.0 * (Y[0] - Y[1]);
    double c1 = R[0] * R[0] - R[1] * R[1];
    double d1 = (X[1] * X[1] + Y[1] * Y[1])
              - (X[0] * X[0] + Y[0] * Y[0]);

    double a2 = 2.0 * (X[0] - X[2]);
    double b2 = 2.0 * (Y[0] - Y[2]);
    double c2 = R[0] * R[0] - R[2] * R[2];
    double d2 = (X[2] * X[2] + Y[2] * Y[2])
              - (X[0] * X[0] + Y[0] * Y[0]);

    double det = a1 * b2 - a2 * b1;

    if (fabs(det) < EPS) {
        return 0;
    }
    double px = (-c1 * b2 + c2 * b1) / det;
    double qx = (-d1 * b2 + d2 * b1) / det;

    double py = (-a1 * c2 + a2 * c1) / det;
    double qy = (-a1 * d2 + a2 * d1) / det;
    double A = px * px + py * py;
    double B = 2.0 * (px * qx + py * qy)
             - 2.0 * X[0] * px
             - 2.0 * Y[0] * py
             - R[0] * R[0];

    double C = qx * qx + qy * qy
             - 2.0 * X[0] * qx
             - 2.0 * Y[0] * qy
             + X[0] * X[0]
             + Y[0] * Y[0];

    double bestS = 1e100;
    double bestX = 0, bestY = 0;
    bool found = false;

    auto check = [&](double s) {
        double x = px * s + qx;
        double y = py * s + qy;

        double t0 = hypot(x - X[0], y - Y[0]) / R[0];
        double t1 = hypot(x - X[1], y - Y[1]) / R[1];
        double t2 = hypot(x - X[2], y - Y[2]) / R[2];

        if (fabs(t0 - t1) > 1e-6) return;
        if (fabs(t0 - t2) > 1e-6) return;
        if (t0 <= 1.0 + 1e-8) return;

        if (s < bestS) {
            bestS = s;
            bestX = x;
            bestY = y;
            found = true;
        }
    };

    if (fabs(A) < EPS) {
        if (fabs(B) < EPS) {
            return 0;
        }
        check(-C / B);
    } else {
        double D = B * B - 4.0 * A * C;

        if (D < -EPS) {
            return 0;
        }

        D = max(0.0, D);
        double root = sqrt(D);

        check((-B + root) / (2.0 * A));

        if (root > EPS) {
            check((-B - root) / (2.0 * A));
        }
    }

    if (found) {
        cout << fixed << setprecision(5)
             << bestX << " " << bestY << '\n';
    }

    return 0;
}