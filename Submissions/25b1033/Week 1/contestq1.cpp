#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
struct rounds{
    string name;
    int score;
};
struct player{
    string name;
    int currentscore;
    int totalscore;
};
int main(){
    int n; 
    cin>>n;
    rounds r[n];
    player p[n];
    int tp=0;
    for(int i=0;i<n;i++){
        cin>>r[i].name>>r[i].score;
        int found=-1;
        for(int j=0;j<tp;j++){
            if(p[j].name==r[i].name){
                found=j;
                p[j].totalscore+=r[i].score;
            }
        }
        if(found==-1){
            p[tp].name=r[i].name;
            p[tp].totalscore=r[i].score;
            p[tp].currentscore=0;
            tp++;
        }
    }
    int winscore=-1000000;
    for(int i=0;i<tp;i++){
        winscore=max(winscore,p[i].totalscore);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<tp;j++){
            if(r[i].name==p[j].name){
                    p[j].currentscore+=r[i].score;
                    if(p[j].totalscore==winscore && p[j].currentscore>=winscore) {cout<<p[j].name;
                    return 0;}
            } 
        }
    }
}