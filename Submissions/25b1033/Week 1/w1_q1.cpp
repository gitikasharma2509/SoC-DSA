#include <iostream>
using namespace std;
typedef long int li;

int main(){
    li x,n,sum=0;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>x;
        sum=sum+x;
    }
    li missing_no = n*(n+1)/2 - sum;
    cout<<missing_no;
}