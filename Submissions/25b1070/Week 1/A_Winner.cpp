#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

int isthere(string name,vector<pair<string,int>> v){
    for(int i=0;i<v.size();i++){
        if(v[i].first==name) return i;
    }
    return -1;
}
void solve() {
    int n,ma=0;
    string first;
    cin>>n;
    vector<pair<string,int>> v,moves;
    for(int i=0;i<n;i++){
        string name;
        int score;
        cin>>name>>score;
        int in=isthere(name,v);
        if (in != -1){
            v[in].second+=score;
        }
        else{
            v.push_back({name,score});
        }
        moves.push_back({name,score});
    }
    for (auto a:v){
        ma=max(ma,a.second);
    }
    vector<pair<string,int>> top_scorers;
    for (auto a:v){
        if(a.second==ma){
            top_scorers.push_back({a.first,0});
        }
    }
    if(top_scorers.size()==1){
        cout<<top_scorers[0].first<<'\n';
        return;
    }
    for (auto move : moves){
        for (int i=0;i<top_scorers.size();i++){
            if(move.first==top_scorers[i].first){
                if(top_scorers[i].second>=ma){
                    cout<<top_scorers[i].first<<'\n';
                    return;
                }
                top_scorers[i].second+=move.second;
                if(top_scorers[i].second>=ma){
                    cout<<top_scorers[i].first<<'\n';
                    return;
                }
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}