#include<bits/stdc++.h>
using namespace std;
int main(){
    long long k;
    cin>>k;
    while(k!=1){
        cout<<k<<" ";
        if(k%2==0) k/=2;
        else k=3*k+1;
    }
    cout<<k;
}
