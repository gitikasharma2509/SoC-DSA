#include <iostream>
#include <algorithm>

int get_luck(int n) {
    int mx = 0, mn = 9;
    while (n > 0) {
        int d = n % 10;
        mx = std::max(mx, d);
        mn = std::min(mn, d);
        n /= 10;
    }
    return mx - mn;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int l, r;
        std::cin >> l >> r;
        int best = -1, ans = l;
        for (int i = l; i <= r; i++) {
            int luck = get_luck(i);
            if (luck > best) {
                best = luck;
                ans = i;
            }
            if (best == 9) break;
        }
        std::cout << ans << "\n";
    }
    return 0;
}