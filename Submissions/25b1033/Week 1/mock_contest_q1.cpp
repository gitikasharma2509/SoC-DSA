#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    ll n,m,a;
    cin>>n>>m>>a;
    ll x,y;
    if(n%a==0) x=n/a;
    else x=1+n/a;
    if(m%a==0) y=m/a;
    else y=1+m/a;
    cout<<x*y;
}