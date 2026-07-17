#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<string, int>> round(n);
    unordered_map<string, int> tot;
    for (int i = 0; i < n;i++){
        cin >> round[i].first >> round[i].second;
        tot[round[i].first] += round[i].second;
    }
    int max_score = INT_MIN;
    for(auto s : tot){
        max_score = max(max_score, s.second);
    }
    unordered_map<string, int> m;
    for(auto x : round){
        m[x.first] += x.second;
        if(tot[x.first]==max_score&&m[x.first]>=max_score){
            cout << x.first << endl;
            return 0;
        }
    }
}