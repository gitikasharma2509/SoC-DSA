#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int max1 = 1;
    int cur = 1;

    for (size_t i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            cur++;
        } else {
            cur = 1;
        }
        max1 = max(max1, cur);
    }

    cout << max1 << "\n";

    return 0;
}