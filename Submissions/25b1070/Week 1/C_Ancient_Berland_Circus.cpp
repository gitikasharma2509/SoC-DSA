#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;
const double PI = acos(-1);


struct Point{
    double x,y;
    Point(double a,double b){
        x=a,y=b;
    }
};



double dis(Point p1,Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
bool check_collinear(vector<Point> v){
    vector<double> di;
    di.push_back(dis(v[0],v[1]));
    di.push_back(dis(v[2],v[1]));
    di.push_back(dis(v[0],v[2]));
    sort(di.begin(),di.end());
    return abs(di[2]-(di[1]+di[0]))<1e-9;
}

void solve() {
    vector<Point> v;
    for(int i=0;i<3;i++){
        double x,y;
        cin>>x>>y;
        v.push_back(Point(x,y));
    }
    // if collinear then triangle area with it as one of its side 
    // else 1/2 r*r*sin gcd ( alpha,beta,gamma ) where it is angle between two point via circumcenter
    
    vector<double> di;
    di.push_back(dis(v[0],v[1]));
    di.push_back(dis(v[2],v[1]));
    di.push_back(dis(v[0],v[2]));
    sort(di.begin(),di.end());
    
    if(check_collinear(v)){
        double area = sqrt(3)*0.25*(di[2])*(di[2]);
        cout<<fixed<<setprecision(6);
        cout<<area;
        return;
    }

    double s = (di[0] + di[1] + di[2]) / 2.0;
    double triangleArea = sqrt(s * (s - di[0]) * (s - di[1]) * (s - di[2]));

    double R = (di[0] * di[1] * di[2]) / (4.0 * triangleArea);

    double A = acos((di[1]*di[1] + di[2]*di[2] - di[0]*di[0]) / (2.0*di[1]*di[2]));
    double B = acos((di[0]*di[0] + di[2]*di[2] - di[1]*di[1]) / (2.0*di[0]*di[2]));
    double C = acos((di[0]*di[0] + di[1]*di[1] - di[2]*di[2]) / (2.0*di[0]*di[1]));

    double alpha = 2.0 * A;
    double beta  = 2.0 * B;
    double gamma = 2.0 * C;

    int ans =100;

    for(int i=3;i<=100;i++){
        double a = alpha*i/(2*PI);
        double b = beta*i/(2*PI);
        double c = gamma*i/(2*PI);
        if(abs(a-round(a))<1e-9 and
           abs(b-round(b))<1e-9 and
           abs(c-round(c))<1e-9){
            ans=i;
            break;
           }
    }
    cout<<fixed<<setprecision(6);
    cout<<0.5*ans*R*R*sin(2*PI/ans)<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}