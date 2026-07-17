#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    long long l=0,r=0,n=s.length(),ma=0,count=0;
    while(r<n){
        if(s[l]==s[r]){
            count++;
            r++;
            continue;
        }
        else{
            l=r;
            ma=max(ma,count);
            count=0;
        }
    }
    ma=max(ma,count);

    cout<<ma<<'\n';
}