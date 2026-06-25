#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    long long W;
    cin >> N >> W;

    vector<long long> weight(N);
    vector<int> value(N);

    int maxValue = 0;

    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> value[i];
        maxValue += value[i];
    }

    const long long INF = 1e18;

    vector<long long> dp(maxValue + 1, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int v = maxValue; v >= value[i]; v--) {
            dp[v] = min(dp[v],
                        dp[v - value[i]] + weight[i]);
        }
    }

    int answer = 0;

    for (int v = maxValue; v >= 0; v--) {
        if (dp[v] <= W) {
            answer = v;
            break;
        }
    }

    cout << answer << endl;

    return 0;
}