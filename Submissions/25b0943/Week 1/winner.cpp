#include <iostream>
#include <string>

using namespace std;

struct Round {
    string name;
    int score;
};

int main() {
    int n;
    cin >> n;

    Round rounds[n];
    string players[n];
    int final_scores[n] = {0};
    int count = 0;

    for (int i = 0; i < n; i++) {
        cin >> rounds[i].name >> rounds[i].score;

        int qwer = -1;
        for (int j = 0; j < count; j++) {
            if (players[j] == rounds[i].name) {
                qwer = j;
                break;
            }
        }

        if (qwer == -1) {
            players[count] = rounds[i].name;
            qwer = count;
            count++;
        }

        final_scores[qwer] += rounds[i].score;
    }

    int max_score = -1000000;
    for (int i = 0; i < count; i++) {
        if (final_scores[i] > max_score) {
            max_score = final_scores[i];
        }
    }

    int current_scores[n] = {0};
    
    for (int i = 0; i < n; i++) {
        int qwer = -1;
        for (int j = 0; j < count; j++) {
            if (players[j] == rounds[i].name) {
                qwer = j;
                break;
            }
        }

        current_scores[qwer] += rounds[i].score;

        if (current_scores[qwer] >= max_score && final_scores[qwer] == max_score) {
            cout << rounds[i].name << endl;
            return 0;
        }
    }

    return 0;
}