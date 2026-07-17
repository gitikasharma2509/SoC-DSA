#include <iostream>
using namespace std;
#include <algorithm>

int luck(long long int N){
    int maxsofar=N%10, minsofar=N%10, digit;
    while(N){
    digit= N % 10;
    maxsofar=max(maxsofar,digit);
    minsofar=min(minsofar,digit);
    N/=10;
    }
    return maxsofar-minsofar;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        long long int l,r,result;
        cin>>l>>r;
        int maxluck=0;
        for(int i=l;i<=r;i++){
            if(maxluck<luck(i)){
                maxluck=luck(i);
                result=i;
            }
        }
        cout<<result<<endl;
    }
}