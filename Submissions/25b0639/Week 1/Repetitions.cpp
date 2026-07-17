#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size(); int i = 0; int j = 1; int maxim = 1;

    while (j < n)
    {
        if (s[j] == s[i]){
            j++;
        }
        else{
            maxim = max(maxim, j - i);
            i = j;
            j++;
        }
    }

    maxim = max(maxim, j - i);   

    cout << maxim;
}