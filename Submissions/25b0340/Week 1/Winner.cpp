#include <iostream>
#include <unordered_map>
#include <vector>


using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<string,int>> rounds;//storing info about order
    unordered_map<string,int> total;//scores
    for(int i = 0; i < n; i++) {
        string name;
        int score;
        cin >> name >> score;
        rounds.push_back({name, score});
        total[name] += score;
    }
    int m = -1000000000;
    for(auto x : total) {
        m = max(m, x.second);
    }
    unordered_map<string,int> curr;
    //taking inputs one by one to reach final answer
    for (auto x : rounds){
        curr[x.first]+=x.second;
        if(curr[x.first]>=m && total[x.first]==m){
            cout<<x.first;
            break;
        }
    }
    return 0;
}