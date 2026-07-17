#include <iostream>
using namespace std;

int main(){
    double x1, y1, r1;
    double x2, y2, r2;
    double x3, y3, r3;

    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    cin >> x3 >> y3 >> r3;

    double A,B,C,D,E,F,G,H;
    A = 2*(x2*r1*r1 - x1*r2*r2);
    B = 2*(y2*r1*r1 - y1*r2*r2);
    C = (x2*x2 + y2*y2)*r1*r1 - (x1*x1 + y1*y1)*r2*r2;

    D = 2*(x3*r1*r1 - x1*r3*r3);
    E = 2*(y3*r1*r1 - y1*r3*r3);
    F = (x3*x3 + y3*y3)*r1*r1 - (x1*x1 + y1*y1)*r3*r3;

    double x = (C*E - F*B)/(A*E - B*D);
    double y = (A*F - C*D)/(A*E - B*D);

    cout << x << " "<< y;
     
    return 0;
}