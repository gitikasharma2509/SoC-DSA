#include <iostream>
using namespace std;
#include <cstdint>
typedef int64_t ll;

int main(){
    ll n;
    cin >> n;
    while(n!=1){
        if(n%2==0) {
            cout<<n<<" ";
            n/=2;
        }
        else {
            cout<<n<<" ";
            n=3*n+1;
        }
    }
    cout<<1<<endl;
}