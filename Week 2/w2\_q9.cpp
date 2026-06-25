#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Range {
    int l, r, idx;
};

struct Fenwick {
    vector<int> bit;
    int n;

    Fenwick(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }

    void add(int idx, int val) {
        while(idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int sum(int idx) {
        int res = 0;
        while(idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

bool cmp(Range a, Range b) {
    if(a.l == b.l) return a.r > b.r;
    return a.l < b.l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Range> ranges(n);
    vector<int> rights;

    for(int i = 0; i < n; i++) {
        cin >> ranges[i].l >> ranges[i].r;
        ranges[i].idx = i;
        rights.push_back(ranges[i].r);
    }

    sort(rights.begin(), rights.end());
    rights.erase(unique(rights.begin(), rights.end()), rights.end());

    for(int i = 0; i < n; i++) {
        ranges[i].r =
            lower_bound(rights.begin(),
                        rights.end(),
                        ranges[i].r)
            - rights.begin() + 1;
    }

    sort(ranges.begin(), ranges.end(), cmp);

    vector<int> contains(n);
    vector<int> contained(n);

    int m = rights.size();

    Fenwick bit1(m);

    for(int i = n - 1; i >= 0; i--) {
        contains[ranges[i].idx] =
            bit1.sum(ranges[i].r);

        bit1.add(ranges[i].r, 1);
    }

    Fenwick bit2(m);

    for(int i = 0; i < n; i++) {
        contained[ranges[i].idx] =
            i - bit2.sum(ranges[i].r - 1);

        bit2.add(ranges[i].r, 1);
    }

    for(int i = 0; i < n; i++) {
        cout << contains[i] << " ";
    }
    cout << "\n";

    for(int i = 0; i < n; i++) {
        cout << contained[i] << " ";
    }
    cout << "\n";

    return 0;
}