#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

int main() {
    
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        long long mn = 0, mx = 0;
        long long cntMn = 1, cntMx = 1;

        for (int i = 0; i < n; i++) {
            long long a;
            cin >> a;

            long long val[4];
            long long ways[4];

            // From current minimum
            val[0] = mn + a;
            ways[0] = cntMn;

            val[1] = llabs(mn + a);
            ways[1] = cntMn;

            // From current maximum
            val[2] = mx + a;
            ways[2] = cntMx;

            val[3] = llabs(mx + a);
            ways[3] = cntMx;

            // If mn == mx, avoid counting the same state twice
            if (mn == mx) {
                ways[2] = 0;
                ways[3] = 0;
            }

            long long newMn = val[0];
            long long newMx = val[0];

            for (int j = 1; j < 4; j++) {
                newMn = min(newMn, val[j]);
                newMx = max(newMx, val[j]);
            }

            long long newCntMn = 0;
            long long newCntMx = 0;

            for (int j = 0; j < 4; j++) {
                if (val[j] == newMn) {
                    newCntMn = (newCntMn + ways[j]) % MOD;
                }
                if (val[j] == newMx) {
                    newCntMx = (newCntMx + ways[j]) % MOD;
                }
            }

            mn = newMn;
            mx = newMx;
            cntMn = newCntMn;
            cntMx = newCntMx;
        }

        cout << cntMx % MOD << "\n";
    }

    return 0;
}