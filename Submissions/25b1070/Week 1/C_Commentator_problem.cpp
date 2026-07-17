#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int INF = 1e18;

struct Point{
    double x,y;
    Point(){
        x=0,y=0;
    }
    Point(double a,double b){
        x=a,y=b;
    }
    void operator=(Point p){
        x=p.x,y=p.y;
    }
};

struct Circle{
    Point centre;
    double radius;
    Circle(Point p,double r){
        centre=p,radius=r;
    }
    Circle(double x,double y,double r){
        centre=Point(x,y),radius=r;
    }
    void operator=(Circle c){
        centre=c.centre;
        radius=c.radius;
    }
    bool operator<(Circle c){
        return radius<c.radius;
    }
};

struct Line{
    double m,c; //y=mx+c
    Line(double m1,double c1){
        m=m1,c=c1;
    }
    Line(double a,double b,double c1){ // ax+by=c 
        m=-a/b;
        c=c1/b;
    }
};

Point foot_of_perpendicular(Point p, Line l1){
    
}


vector<Point> sol_line_line(Line l1,Line l2){
    double m1=l1.m,m2=l2.m,c1=l1.c,c2=l2.c;
    vector<Point> v;
    if(m1!=m2){
        double x=(c2-c1)/(m1-m2);
        double y=m1*x+c1;
        v.push_back(Point(x,y));
        return v;
    }
    if(c1!=c2) return v;
    v.push_back(Point(0,c1));
    v.push_back(Point(-1*c1/m1,0));
    return v; 
}

void solve() {
    vector<Circle> circles;
    for(int i=0;i<3;i++){
        double x,y,r;
        cin>>x>>y>>r;
        circles.push_back(Circle(x,y,r));
    }
    sort(circles.begin(),circles.end());//sorting is based on radius
    double x1=circles[0].centre.x,x2=circles[1].centre.x,x3=circles[2].centre.x;
    double y1=circles[0].centre.y,y2=circles[1].centre.y,y3=circles[2].centre.y;
    double r1=circles[0].radius,r2=circles[1].radius,r3=circles[2].radius;
    if(circles[0].radius==circles[2].radius){ // this implies all have equal radius
        Line l1(2*(x2-x1),2*(y2-y1),(x2*x2+y2*y2)-(x1*x1+y1*y1));
        Line l2(2*(x3-x2),2*(y3-y2),(x3*x3+y3*y3)-(x2*x2+y2*y2));
        auto a = sol_line_line(l1,l2);
        if(a.size()==0) return;
        else if(a.size()==1) {
            cout<<fixed<<setprecision(5);
            cout<<a[0].x<<' '<<a[0].y<<'\n';
            return;
        }
        else{
            auto p=foot_of_perpendicular(Point(x1,y1),l1);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}