#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int rounds;
    cin >> rounds;

    vector<pair<string, int>> full;
    unordered_map<string, int> game;
    for(int i = 0; i < rounds; i++){
        string name;
        int score;
        cin >> name >> score;
        full.push_back({name, score});
        bool found = false;
        for(auto &player : game){
            if(player.first == name){
                player.second += score;
                found = true;
                break;
            }
        }
        if(!found){
            game[name] = score;
        }
    }

    string winner;
    int max_score = 0;
    for(auto &player : game){
        if(player.second > max_score){
            max_score = player.second;
        }
    }

    unordered_map<string, int> cur;

    for (auto &[name, score] : full) {
        cur[name] += score;

        if (cur[name] >= max_score && game[name] == max_score) {
            cout << name << '\n';
            return 0;
        }
    }

}