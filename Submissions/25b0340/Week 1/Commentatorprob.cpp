#include<iostream>
#include <cmath>

using namespace std;

float x1, y1, x2, y2, x3, y3, r1, r2, r3;
int main(){
    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    cin >> x3 >> y3 >> r3;
    float x=0;
    float y=0;
    float A=-2*((r3*r3)*x1-(r1*r1)*x3)*(r2*r2-r1*r1)+2*((r2*r2)*x1-(r1*r1)*x2)*(r3*r3-r1*r1);
    float B=-2*((r3*r3)*y1-(r1*r1)*y3)*(r2*r2-r1*r1)+2*((r2*r2)*y1-(r1*r1)*y2)*(r3*r3-r1*r1);
    float C=((r3*r3)*(x1*x1+y1*y1)-(r1*r1)*(x3*x3+y3*y3))*(r2*r2-r1*r1)-((r2*r2)*(x1*x1+y1*y1)-(r1*r1)*(x2*x2+y2*y2))*(r3*r3-r1*r1);

    float A1=-2*((r3*r3)*x2-(r2*r2)*x3)*(r1*r1-r2*r2)+2*((r1*r1)*x2-(r2*r2)*x1)*(r3*r3-r2*r2);
    float B2=-2*((r3*r3)*y2-(r2*r2)*y3)*(r1*r1-r2*r2)+2*((r1*r1)*y2-(r2*r2)*y1)*(r3*r3-r2*r2);
    float C2=((r3*r3)*(x2*x2+y2*y2)-(r2*r2)*(x3*x3+y3*y3))*(r1*r1-r2*r2)-((r1*r1)*(x2*x2+y2*y2)-(r2*r2)*(x1*x1+y1*y1))*(r3*r3-r2*r2);
    float det = A * B2 - A1 * B;

    if(abs(det) < 1e-9){
        cout << "-1";
    }
    else{
        x = (B2 * C - B * C2) / det;
        y = (C * A1 - C2 * A) / det;

        cout << x << " " << y;
    }
}