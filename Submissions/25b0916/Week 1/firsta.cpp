#include<iostream>
#include<string>
using namespace std;
struct Round{
    string name;
    int score;
};

struct Player{
    string name;
    int finalScore;
    int currentScore;
};
int main(){
    int n;
    cin>>n;
    Round rounds[n];
    Player players[n];
    int totalplayers=0;
    for(int i=0;i<n;i++){
        cin>> rounds[i].name>>rounds[i].score;
        int found = -1;

        for(int j = 0; j < totalplayers; j++){

            if(rounds[i].name == players[j].name){
                found = j;
                break;
            }
        }

        if(found == -1){

            players[totalplayers].name = rounds[i].name;
            players[totalplayers].finalScore = rounds[i].score;
            players[totalplayers].currentScore = 0;

            totalplayers++;
        }
        else{
            players[found].finalScore += rounds[i].score;
        }
    }

    // maximum final score
    int mx = -1000000;

    for(int i = 0; i < totalplayers; i++){

        if(players[i].finalScore > mx){
            mx = players[i].finalScore;
        }
    }
    for(int i = 0; i < n; i++){

        for(int j = 0; j < totalplayers; j++){

            if(players[j].name == rounds[i].name){

                players[j].currentScore += rounds[i].score;

                if(players[j].finalScore == mx &&
                   players[j].currentScore >= mx){

                    cout << players[j].name<<"\n";
                    return 0;
                }
            }
        }
    }
    return 0;
}