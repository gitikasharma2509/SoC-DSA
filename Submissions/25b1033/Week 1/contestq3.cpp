#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    int x1,y1,r1,x2,y2,r2,x3,y3,r3;
    cin>>x1>>y1>>r1>>x2>>y2>>r2>>x3>>y3>>r3;
    double x,y,t;
    int a=2*x2-2*x1;
    int b=2*y2-2*y1;
    int c=r1*r1-r2*r2;
    int d=x2*x2+y2*y2-x1*x1-y1*y1;
    int e=2*x3-2*x2;
    int f=2*y3-2*y2;
    int g=r2*r2-r3*r3;
    int h=x3*x3+y3*y3-x2*x2-y2*y2;
    int det=b*e-a*f;
    double p=1.0*(e*c-a*g)/det;
    double q=1.0*(d*e-a*h)/det;
    double r=1.0*(b*g-c*f)/det;
    double s=1.0*(b*h-d*f)/det;
    double u=q-y2;
    double v=s-x2;
    double l=p*p+r*r;
    double m=2*r*v+2*p*u-r2*r2;
    double n=u*u+v*v;
    const double EPS = 1e-9;
    bool found = false;

    if (fabs(l) < EPS) {
        if (fabs(m) > EPS) {
            t = ((-1.0)*n)/ m;
            if (t > 1) found = true;
        }
    }
    else {
        double D = m*m - 4*l*n;

        if (D >= -EPS) {
            D = max(0.0, D);

            double t1 = (-m - sqrt(D)) / (2.0*l);
            double t2 = (-m + sqrt(D)) / (2.0*l);

            double best = 1e100;

            if (t1 > 1) best = min(best, t1);
            else if (t2 > 1) best = min(best, t2);

            if (best < 1e99) {
                t = best;
                found = true;
            }
        }
    }
    if (found) {
        double x = r * t + s;
        double y = p * t + q;

        cout << fixed << setprecision(5);
        cout << x << " " << y << '\n';
    }
}