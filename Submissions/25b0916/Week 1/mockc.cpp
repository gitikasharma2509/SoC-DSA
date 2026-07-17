#include <iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int main(){
   double pi=acos(-1.0);
   double x1,y1,x2,y2,x3,y3;
   cin>>x1>>y1>>x2>>y2>>x3>>y3;
   double a=((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
   double b=((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
   double c=((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
   double x=sqrt(a);
   double y=sqrt(b);
   double z=sqrt(c);
   double a1=(180.0/pi)*acos((a+b-c)/(2*x*y));
   double a2=(180.0/pi)*acos((a-b+c)/(2*x*z));
   double a3=(180.0/pi)*acos((b+c-a)/(2*y*z));
   int n=0;
   for(int i=3;i<1000;i++){
      int b1=round(a1*i);
      int b2=round(a2*i);
      int b3=round(a3*i);
      if(b1%180==0 && b2%180==0 && b3%180==0){
         n=i;
         break;
      }
   }
   double ans=(n*a*b*c*sin(2*pi/n))/(2*(x+y+z)*(x+y-z)*(x-y+z)*(y+z-x));
   cout << fixed << setprecision(6);
   cout<<ans;
}