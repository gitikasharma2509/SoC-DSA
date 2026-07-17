#include <bits/stdc++.h>
using namespace std;

struct Player {
    string name;
    long long score;
    long long round;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n;
    cin >> n;
    vector<Player> players,candidates;
    long long score1, max_score;
    string name1,winner;
    cin >> name1 >> score1;
    players.push_back({name1, score1, 1});
    for (long long i = 1; i < n; i++) {
        string name;
        long long score;
        cin >> name >> score;
        int k=0;
        for (long long j = 0; j < players.size(); j++) {
            if (players[j].name == name) {
                k=1;
                players[j].score += score;
                players[j].round = i + 1;
            }
            
        }
        if (k == 0) {
            players.push_back({name, score, i + 1});
        }
    }
    max_score = players[0].score;
    for (long long i = 1; i < players.size(); i++) {
        if (players[i].score > max_score) {
            max_score = players[i].score;
        }
    }
    for(long long i = 0; i < players.size(); i++) {
        if (players[i].score == max_score) {
            candidates.push_back(players[i]);
            if (candidates.size() == 2) {
                if (candidates[0].round < candidates[1].round) {
                    winner = candidates[0].name;
                    candidates.erase(candidates.begin() + 1);
                } else {
                    winner = candidates[1].name;
                    candidates.erase(candidates.begin());
                }
            }
            else {
                winner = candidates[0].name;
            }
        }
    }
    cout << winner << endl;
    return 0;
}