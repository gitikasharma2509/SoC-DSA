#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> pos(n + 1);

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            pos[x] = i;
        }

        int l = 1;
        int r = n;

        while (l < r) {
            if (pos[l] < pos[l + 1] &&
                pos[r - 1] < pos[r] &&
                pos[l] < pos[r]) {
                l++;
                r--;
            } else {
                break;
            }
        }

        cout << (r - l + 1) / 2 << "\n";
    }

    return 0;
}