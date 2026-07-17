#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long l, r;
        cin >> l >> r;

        long long ans = l;
        int i = -1;

        for (long long x = l; x <= r && x <= l + 100; x++) {
            long long temp = x;
            int mn = 9;
            int mx = 0;

            while (temp > 0) {
                int d = temp % 10;
                mn = min(mn, d);
                mx = max(mx, d);
                temp /= 10;
            }
            int luck = mx - mn;
            if (luck > i) {
                i = luck;
                ans = x;
            }
            if (i == 9) {
                break;
            }
        }
        cout << ans << "\n";
    }

    return 0;
}