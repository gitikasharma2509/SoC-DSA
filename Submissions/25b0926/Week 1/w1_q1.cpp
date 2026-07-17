#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,k;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n-1;i++){
        cin>>k;
        v[k-1]=k;
    }
    for(int i=0;i<n;i++){
        if(v[i]==0) cout<<i+1<<endl;
    }
}