#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v(n),positions(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
        positions[v[i]-1]=i;
    }
    int count=0;
    for(int i=0;i<n-1;i++){
        if(positions[i]>positions[i+1]) count++;
    }
    cout<<count+1<<'\n';
}