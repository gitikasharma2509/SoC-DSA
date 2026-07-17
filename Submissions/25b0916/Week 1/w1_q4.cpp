#include<iostream>
using namespace std;
int luckiness(int x){
    int m=9,n=0;
    while(x>0){
        int d = x%10;
        m = min(d,m);
        n = max(d,n);
        x = x/10;
    }
    return n-m;
}
int main(){
    int t,a,b,best;
    cin>>t;
    int c[t];
    for(int i=0;i<t;i++){
        cin>>a>>b;
        // Optimization:
        // Maximum possible luckiness is 9,
        // so checking more than 100 numbers is unnecessary
        b=min(b,a+100);
        best=a;
        while(b>=a){
            if (luckiness(b)>luckiness(best))
                best=b;
            b--;
        }
        c[i]=best;
    }
    for (int i = 0; i < t; i++)
    {
        cout<<c[i]<<'\n';
    }
    
}