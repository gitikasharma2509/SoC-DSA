#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    cin>>s;
    long a=1,b=1;
    for(long i=1;i<s.size();i++){
        if(s[i]==s[i-1]){
            a++;
        }
        else{
            b= max(a,b);
            a=1;
        }
    }
    b=max(a,b);
    cout<<b<<'\n';
}