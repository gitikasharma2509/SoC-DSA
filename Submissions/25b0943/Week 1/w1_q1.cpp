#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int num[n - 1];

    for (int i = 0; i < n - 1; ++i) {
        cin >> num[i];
    }

    sort(num, num + (n - 1));

    for (int i = 0; i < n - 1; ++i) {
        if (num[i] != i + 1) {
            cout << i + 1 << "\n";
            return 0;
        }
    }

    cout << n << "\n";

    return 0;
}