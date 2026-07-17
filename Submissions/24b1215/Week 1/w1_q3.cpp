#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    vector<pair<unsigned long long, unsigned long long>> tests;

    for(int i = 0; i < t; i++) {
        unsigned long long n, k;
        cin >> n >> k;

        tests.push_back({n, k});
    }

    for(auto p : tests) {
        unsigned long long n = p.first;
        unsigned long long k = p.second;

        bool found = false;

        for(unsigned long long y = 0; y <= n / k; y++) {
            unsigned long long rem = n - k * y;

            if(rem % 2 == 0) {
                found = true;
                break;
            }
        }

        if(found)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}