#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> ans;

void solve(int n , int source , int destination , int helper)
{
    if(n == 1){
       
        ans.push_back({source, destination});
        return;
    }

    solve(n - 1, source , helper , destination);

    
    ans.push_back({source , destination});

    solve(n - 1, helper, destination , source);
}

int main()
{
    int n;
    cin >> n;

    solve(n, 1, 3, 2);

    cout << ans.size() << endl;

    for(auto move : ans) {
       
        cout << move.first << " " << move.second << endl; 
    }

    return 0;
}