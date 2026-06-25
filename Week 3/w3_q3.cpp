#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<long long> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int dice = 1; dice <= 6; dice++) {
            if (i - dice >= 0) {
                dp[i] = (dp[i] + dp[i - dice]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}