#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long n;
    cin >> n;
    set<long> numbers;
    for(long i=0; i<n; i++) {
        long x;
        cin >> x;
        numbers.insert(x);
    }
    cout << numbers.size() << endl;
    return 0;
}