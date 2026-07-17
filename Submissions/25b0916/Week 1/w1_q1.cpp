#include<iostream>
using namespace std;
int main(){
    long n,x,sum;
    cin>>n;
    sum = n*(n+1)/2;
    for(long i=1; i<n;i++){
        cin>>x;
        sum = sum - x;
    }
    cout<<sum<<'\n';
}