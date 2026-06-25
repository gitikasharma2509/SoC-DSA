#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long ans = 0;
        int cnt = 0;

        for (int i = 0; i < n - 1; i++) {

            if (a[i] < 2 * a[i + 1]) {
                cnt++;
            } else {
                cnt = 0;
            }

            if (cnt >= k) {
                ans++;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}