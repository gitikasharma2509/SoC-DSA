#include <bits/stdc++.h>
using namespace std;

struct coordinate {
    long double x;
    long double y;
};
long double length(coordinate a, coordinate b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y - b.y)*(a.y - b.y));
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<coordinate> c(3);
    long double n;
    for(int i=0; i<3; i++){
        cin >> c[i].x >> c[i].y;
    }
    long double a = length(c[0], c[1]);
    long double b = length(c[1], c[2]);
    long double d = length(c[2], c[0]);

    if(abs(a-b) < 1e-9 && abs(b-d) < 1e-9){
        cout << fixed << setprecision(6) << (3*a*a*tan(60.0/2))/4 << "\n";
    }

    else if(abs(a-b) < 1e-9){
        long double theta = acos((a*a + b*b - d*d)/(2*a*b));
        n = 360.0/(180-theta);
        cout << fixed << setprecision(6) << (n*a*a*tan(theta/2))/4 << "\n";
    }
    else if(abs(b-d) < 1e-9){
        long double theta = acos((b*b + d*d - a*a)/(2*b*d));
        n = 360.0/(180-theta);
        cout << fixed << setprecision(6) << (n*b*b*tan(theta/2))/4 << "\n";
    }
    else if(abs(a-d) < 1e-9){
        long double theta = acos((a*a + d*d - b*b)/(2*a*d));
        n = 360.0/(180-theta);
        cout << fixed << setprecision(6) << (n*d*d*tan(theta/2))/4 << "\n";
    }
    return 0;
}