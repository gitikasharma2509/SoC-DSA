#include <iostream>
#include <vector>

using namespace std;

bool possible(long long time, const vector<long long>& machines, long long t) {
    long long products = 0;

    for (int i = 0; i < machines.size(); i++) {
        products += time / machines[i];

        if (products >= t) {
            return true;
        }
    }

    return false;
}

int main() {
    long long n, t;
    cin >> n >> t;

    vector<long long> machines(n);

    for (int i = 0; i < n; i++) {
        cin >> machines[i];
    }

    long long low = 0;
    long long high = 1000000000000000000LL;
    long long answer = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (possible(mid, machines, t)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << answer << endl;

    return 0;
}