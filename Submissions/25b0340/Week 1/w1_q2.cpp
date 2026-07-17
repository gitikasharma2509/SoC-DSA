#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cin>>s;
    int n1=1;
    int n2=1;
    for(int i=1; i<s.size(); i++){
        if (s[i]==s[i-1]){
            n1++;
            if (n2<n1){
                n2=n1;
            }
        }
        else{
            n1=1;
        }
    }
    cout<<n2;
}
