#include <iostream>
#include <unordered_map>
#include <string>
#include <utility>
#include <vector>
 
using namespace std;
int main()
{
    unordered_map<string, int> names_scores;
    int n;
    cin >> n;
    vector<pair<string, int>> rounds(n);
    int max = -1001;
   for(int i = 0; i < n; i++){
        string name;
        cin >> name;
        rounds[i].first = name;
        int score;
        cin >> score;
        rounds[i].second = score;
        names_scores[name] += score;
    }
    for(auto const& item : names_scores){
            if(item.second > max){
                max = item.second;
            }
    }
    unordered_map <string, int> past_scores;
    for(int i = 0; i < n; i++){
        string name = rounds[i].first;
        int score = rounds[i].second;
        past_scores[name] += score;
        if(names_scores[name] == max && past_scores[name] >= max){
            cout << name << endl;
            break;
        }
    }
    
}
