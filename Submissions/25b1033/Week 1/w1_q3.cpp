#include <iostream>
using namespace std;
typedef long long ll;
bool burles(ll n,ll k){
    if(n%2==0) return true;
    if(k%2==1) return true;
    return false;
}
int main(){
    int t;
    cin>>t;
    ll n[t],k[t];
    bool out[t];
    for(int i=0;i<t;i++){
        cin>>n[i];
        cin>>k[i];
        out[i]=burles(n[i],k[i]);
    }
    for(int i=0;i<t;i++){
        if(out[i]){
            cout<<"YES"<<'\n';
        }
        else{
            cout<<"NO"<<'\n';
        }
    }
}