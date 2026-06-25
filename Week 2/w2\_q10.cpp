#include <iostream>
#include <vector>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void add(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int sum(int idx) {
        int res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }

    int rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> rowCnt(n + 1, 0);
    vector<int> colCnt(n + 1, 0);

    Fenwick rowBit(n);
    Fenwick colBit(n);

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, y;
            cin >> x >> y;

            rowCnt[x]++;
            colCnt[y]++;

            if (rowCnt[x] == 1)
                rowBit.add(x, 1);

            if (colCnt[y] == 1)
                colBit.add(y, 1);
        }

        else if (t == 2) {
            int x, y;
            cin >> x >> y;

            rowCnt[x]--;
            colCnt[y]--;

            if (rowCnt[x] == 0)
                rowBit.add(x, -1);

            if (colCnt[y] == 0)
                colBit.add(y, -1);
        }

        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            int rows =
                rowBit.rangeSum(x1, x2);

            int cols =
                colBit.rangeSum(y1, y2);

            if (rows == x2 - x1 + 1 ||
                cols == y2 - y1 + 1)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}