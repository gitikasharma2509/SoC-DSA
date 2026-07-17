#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, a, x, y;
    cin >> n >> m >> a;

    x = ceil((double)m / a);
    y = ceil((double)n / a);
    cout << x * y;
}