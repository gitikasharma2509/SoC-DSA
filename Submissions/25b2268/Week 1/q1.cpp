#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int sum = 0;
    for(int i = 0; i < n-1; i++){
        int x;
        cin>>x;
        sum += x;
    }
    int sum2 = 0;
    for(int i = 1; i <=n; i++){
        sum2 += i;
    }
    int num = sum2 - sum;
    cout<<num<<endl;
    return 0;
}