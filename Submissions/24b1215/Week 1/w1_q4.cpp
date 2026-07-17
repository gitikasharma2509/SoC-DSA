#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    long long l, r;

    cin >> t;

    vector<pair<long long, long long>> nums;

    for(int i = 0; i < t; i++) {
        cin >> l >> r;
        nums.push_back({l, r});
    }

    for(auto p : nums) {
        l = p.first;
        r = p.second;

        int maxi = -1;
        long long ans = l;

        for(long long num = l; num <= r; num++) {

            string s = to_string(num);

            int largest = *max_element(s.begin(), s.end());
            int smallest = *min_element(s.begin(), s.end());

            int diff = largest - smallest;

            if(diff > maxi) {
                maxi = diff;
                ans = num;
            }
        }

        cout << ans << endl;
    }
}