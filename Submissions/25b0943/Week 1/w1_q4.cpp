#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;

        int max1 = -1;
        int luck = l;

        for (int i = l; i <= r; ++i) {
            int cur = i;
            int max2 = 0;
            int min2 = 9;

            while (cur > 0) {
                int digit = cur % 10;
                max2 = max(max2, digit);
                min2 = min(min2, digit);
                cur /= 10;
            }

            int luckiness = max2 - min2;

            if (luckiness > max1) {
                max1 = luckiness;
                luck = i;
            }

            if (max1 == 9) {
                break;
            }
        }

        cout << luck << "\n";
    }

    return 0;
}