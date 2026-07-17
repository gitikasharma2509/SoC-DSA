#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long curr = 1;
    long long ans = 1;

    for(int i = 1; i < s.size(); i++) {
        if(s[i] == s[i - 1])
            curr++;
        else
            curr = 1;

        ans = max(ans, curr);
    }

    cout << ans << endl;
}