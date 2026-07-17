#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long last=0;
    long long tot=0;
    for(int i=0;i<n;i++){
        long long temp;
        cin>>temp;
        tot += max(0LL,last-temp);
        last= max(last,temp);
    }
    cout<<tot<<"\n";
}
