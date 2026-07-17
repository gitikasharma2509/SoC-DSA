#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
   long long n;
   cin>>n;
   vector<string> v;
   string p = "YES";
   string m = "NO";
   for(int i = 0; i < n; i++){
    long long x,y;
    cin>>x>>y;
    if((2+y) == x){
        v.push_back(p);
        continue;
    }
     if(x < y && x%2 != 0){
        v.push_back(m);
        continue;
    }
    if(x%2 == 0 || (y!= 0 && x%y == 0)){
        v.push_back(p);
        continue;
    }
    if(x%2 != 0 && y%2 == 0){
        v.push_back(m);
        continue;
    }
    if(x%2 != 0 && y%2 != 0 && x > y){
        v.push_back(p);
        continue;
    }
      if((2+y) > x){
        v.push_back(m);
        continue;
    }
   }
   for(int i = 0; i < v.size(); i++){
    cout<<v[i]<<endl;
   } 
    return 0;
}