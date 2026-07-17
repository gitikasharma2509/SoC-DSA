#include<iostream>
#include<unordered_map>
#include<vector>
#include<utility>
using namespace std;

int main(){
    long long n;
    vector<pair<string,int>> rounds; 
    string ans1;
    long long max1 = 0;
    cin>>n;
    unordered_map<string, long long> points;
    unordered_map<string, long long> points1;
    for(int i = 0; i < n; i++){
        string s;
        long long p;
        cin>>s;
        cin>>p;
        rounds.push_back({s,p});
        points[s] += p;
    }
    int maxans = 0;
    for(auto i : points){
        if(i.second > maxans){
            maxans = i.second;
            ans1 = i.first;
        }
    }
    int count = 0;
    for(auto i : points){
        if(i.second == maxans) count++;
    }
    if(count == 1){
    cout<<ans1<<endl;
    }
    if(count > 1){
        for(int i = 0; i < n; i++){
            points1[rounds[i].first] += rounds[i].second;
          if(points1[rounds[i].first] >= maxans && points[rounds[i].first] == maxans){
            ans1 = rounds[i].first;
            break;
          }
        }
        cout<<ans1<<endl;
    }
    return 0;
}