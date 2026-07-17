#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> names;
    vector<int> scores;

    map<string,int> finalscore;

    for(int i = 0; i < n; i++)
    {
        string name;
        int sc;

        cin >> name >> sc;

        names.push_back(name);
        scores.push_back(sc);

        finalscore[name] += sc;
    }

    int maxi = -1e5;

    for(auto p : finalscore)
    {
        maxi = max(maxi, p.second);
    }

    map<string,int> current;

    for(int i = 0; i < n; i++)
    {
        current[names[i]] += scores[i];

        if(current[names[i]] >= maxi &&
           finalscore[names[i]] == maxi)
        {
            cout << names[i] << endl;
            break;
        }
    }

    return 0;
}