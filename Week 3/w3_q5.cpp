#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;
const int MAXN = 1000000;

int main() {
    int t;
    cin >> t;

    vector<long long> dp1(MAXN + 1);
    vector<long long> dp2(MAXN + 1);

    dp1[1] = 1;
    dp2[1] = 1;

    for (int i = 2; i <= MAXN; i++) {
        dp1[i] = (4 * dp1[i - 1] + dp2[i - 1]) % MOD;
        dp2[i] = (dp1[i - 1] + 2 * dp2[i - 1]) % MOD;
    }

    while (t--) {
        int n;
        cin >> n;
        cout << (dp1[n] + dp2[n]) % MOD << "\n";
    }

    return 0;
}