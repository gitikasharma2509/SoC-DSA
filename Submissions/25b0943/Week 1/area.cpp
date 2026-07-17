#include<iostream>
#include<cmath>
using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-5;

double dist(double x1, double y1, double x2, double y2) {
    	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool isMultiple(double angle, double base) {
    double ratio = angle / base;
    return fabs(ratio - round(ratio)) < EPS;
}

int main(){
	double x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	double a = dist(x2, y2, x3, y3);
    double b = dist(x1, y1, x3, y3);
    double c = dist(x1, y1, x2, y2);
	
	double area = fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
	double R = (a * b * c) / (4.0 * area);

	double A = acos((2 * R * R - a * a) / (2 * R * R));
    double B = acos((2 * R * R - b * b) / (2 * R * R));
    double C = acos((2 * R * R - c * c) / (2 * R * R));

	 int n = -1;
    for (int k = 3; k <= 100; k++) {
        double base = 2 * PI / k;
        if (isMultiple(A, base) && isMultiple(B, base) && isMultiple(C, base)) {
            n = k;
            break;
        }
    }

	double ans = (n * R * R * sin(2 * PI / n)) / 2.0;

    cout << fixed;
    cout.precision(8);
    cout << ans << '\n';

    return 0;
}
