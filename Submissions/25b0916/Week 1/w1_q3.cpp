#include<iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    long long a,b;
    int c[t];
    for(int i=0;i<t;i++){
        cin>>a>>b;
        if(a%2==0)
            c[i]=1;
        else if(a%2==1 && b%2==1)
            c[i]=1;
        else
            c[i]=0;
    }
    for(int i=0;i<t;i++){
        if(c[i]==1)
            cout<<"YES\n";
        else if(c[i]==0)
            cout<<"NO\n";
    }
}