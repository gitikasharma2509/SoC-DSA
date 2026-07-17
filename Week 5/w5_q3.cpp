#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string s;
        cin >> s;

        int n = s.size();

        // Most significant digit must be 1
        if (s[0] != '1') {
            cout << "NO\n";
            continue;
        }

        bool ok = true;

        // Least significant digit (no incoming carry)
        if (s[n - 1] == '9')
            ok = false;

        // Middle digits (incoming carry = 1)
        for (int i = 1; i < n - 1 && ok; i++) {
            if (s[i] == '0')
                ok = false;
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}