#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long l, r;
        cin >> l >> r;

        long long best_num = l;
        int max_luck = -1;

        long long limit = l + 100;
        if (r < limit) {
            limit = r;
        }

        for (long long j = l; j <= limit; j++) {
            long long n = j;
            int lar = 0;
            int sl = 9;

            while (n > 0) {
                int dig = n % 10;
                
                if (dig > lar) {
                    lar = dig;
                }
                if (dig < sl) {
                    sl = dig;
                }
                
                n /= 10;
            }

            int luck_curr = lar - sl;

            if (luck_curr > max_luck) {
                max_luck = luck_curr;
                best_num = j;
            }

            if (max_luck == 9) {
                break;
            }
        }

        cout << best_num << "\n";
    }

    return 0;
}