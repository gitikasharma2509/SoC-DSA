#include <iostream>
#include <iomanip>
#include<cmath>
using namespace std;
 
int main() {
 
    double x1,y1,r1;
    double x2,y2,r2;
    double x3,y3,r3;
 
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    cin >> x3 >> y3 >> r3;
    double k,x,y;
    double A1 = 2*(x2-x1);
    double B1 = 2*(y2-y1);
    double C1 = x2*x2+y2*y2 - x1*x1 - y1*y1;
    double D1 = r1*r1 - r2*r2;
    double A2 = 2*(x3-x2);
    double B2 = 2*(y3-y2);
    double C2 = x3*x3+y3*y3 - x2*x2 - y2*y2;
    double D2 = r2*r2-r3*r3;
    double det = A2*B1 - A1*B2;

    double px = 1.00*(C2*B1 - C1*B2)/det;
    double qx = 1.00*(D2*B1 - D1*B2)/det;
 
    double py = 1.00*(A2*C1 - A1*C2)/det;
    double qy = 1.00*(A2*D1 - A1*D2)/det;
 
    double qa = qx*qx + qy*qy;
    double qb = 2*qx*(px-x2) + 2*qy*(py-y2) - r2*r2;
    double qc = (px-x2)*(px-x2) + (py-y2)*(py-y2);
    if(qa<=1e-9){
        y = py;
        x = px;
        cout << fixed << setprecision(5);
        cout << x << " " << y << "\n";
    }
    else{
        
 
        double disc = qb*qb - 4*qa*qc;
        if(disc>1e-5){
        double t1 = (-qb + sqrt(disc))/(2.00*qa);
        double t2 = (-qb - sqrt(disc))/(2.00*qa);

        double t;
 
        if(t1 > 1e-5 && t2 > 1e-5)
            t = min(t1,t2);
        else if(t1 > 1e-5)
            t = t1;
        x = px + qx*t;
        y = py + qy*t;
        cout << fixed << setprecision(5);
        cout << x << " " << y << "\n";
    }
        else return 0;
 
    }
}