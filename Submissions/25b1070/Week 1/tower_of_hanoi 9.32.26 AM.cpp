#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> toh(int n,int left,int middle,int right){
    vector<pair<int,int>> v1;
    vector<pair<int,int>> v2;
    if (n>1) v1 = toh(n-1,left,right,middle);
    if (n>1) v2 = toh(n-1,middle,left,right);
    v1.push_back({left,right});
    v1.insert(v1.end(),v2.begin(),v2.end());
    return v1;
}
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v =toh(n,1,2,3);
    cout<<v.size()<<"\n";
    for (pair a : v){
        cout<<a.first<<" "<<a.second<<"\n";
    }
}
