#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double dist(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2) +
                (y1-y2)*(y1-y2));
}

int main()
{
    double x1,y1,r1;
    double x2,y2,r2;
    double x3,y3,r3;

    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    cin >> x3 >> y3 >> r3;

    for(double x0=-1000;x0<=1000;x0+=0.5)
    {
        for(double y0=-1000;y0<=1000;y0+=0.5)
        {
            double CP = dist(x0,y0,x1,y1);
            double CQ = dist(x0,y0,x2,y2);
            double CR = dist(x0,y0,x3,y3);

            if(CP < r1 || CQ < r2 || CR < r3)
                continue;

            double cos1 =
            ((x1-x0)*(x2-x0) + (y1-y0)*(y2-y0))
            /(CP*CQ);

            double cos2 =
            ((x2-x0)*(x3-x0) + (y2-y0)*(y3-y0))
            /(CQ*CR);

            double cos3 =
            ((x3-x0)*(x1-x0) + (y3-y0)*(y1-y0))
            /(CR*CP);

            if(abs(cos1-cos2) < 0.01 &&
               abs(cos2-cos3) < 0.01)
            {
                cout << fixed << setprecision(5);
                cout << x0 << " " << y0 << endl;
                return 0;
            }
        }
    }

    return 0;
}