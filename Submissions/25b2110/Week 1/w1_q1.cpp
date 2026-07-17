#include <iostream>
using namespace std;

int main(){
long long n;
cin>>n;
long long ans1=0;

int input;
for(int i=1;i<n;i++){
    cin>>input;
    ans1+=input;
}

 long long total=n*(n+1)/2; //idea is to subtract the total sum between i to n with the inputs

cout<<total-ans1;



}
