#include <iostream>
using namespace std;
#include <cmath>
#include <vector>

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    long long n;
    cin >> n;
    long long sum = 0;
    for (long long i = 0; i < n-1; i++) {
        long long x;
        cin >> x;
        sum = sum + x;
    }
    long long total_sum = n * (n + 1) / 2;
    cout << total_sum - sum << "\n";
    return 0;
}