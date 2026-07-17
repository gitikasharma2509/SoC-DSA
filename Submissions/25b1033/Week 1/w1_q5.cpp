#include <iostream>
using namespace std;
typedef long int li;
int main(){
    li n;
    cin>>n;
    while(n!=1){
        cout<<n<<" ";
        if(n%2==0)
            n=n/2;
        else
            n=3*n+1;
    }
    cout<<"1";
}