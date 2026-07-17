#include <iostream>
using namespace std;
 int main(){
    int t;
    cin>>t;
    while(t>0){
        long long int n,k;
        cin>>n>>k;
        if(k%2==0 && n%2!=0){
                cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;
        t--;
    }
 }