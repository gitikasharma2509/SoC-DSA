#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> vals = a;
    sort(vals.begin(), vals.end());

    vector<long long> dp(n), ndp(n);

    for (int j = 0; j < n; j++) {
        dp[j] = llabs(a[0] - vals[j]);
    }

    for (int i = 1; i < n; i++) {
        long long pref = dp[0];
        ndp[0] = pref + llabs(a[i] - vals[0]);

        for (int j = 1; j < n; j++) {
            pref = min(pref, dp[j]);
            ndp[j] = pref + llabs(a[i] - vals[j]);
        }

        dp.swap(ndp);
    }

    long long ans = dp[0];
    for (int j = 1; j < n; j++) {
        ans = min(ans, dp[j]);
    }

    cout << ans << endl;
    return 0;
}