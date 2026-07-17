#include <bits/stdc++.h>
using namespace std;

void printHanoi(int n, int from, int mid, int to) {
    if (n == 1) {
        cout << from << " " << to << "\n";
        return;
    }
    printHanoi(n - 1, from, to, mid);
    cout << from << " " << to << "\n";
    printHanoi(n - 1, mid, from, to);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    printHanoi(n, 1, 2, 3);
    return 0;
}