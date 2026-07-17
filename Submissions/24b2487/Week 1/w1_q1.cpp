#include <iostream>

int main() {
    long long n, sum = 0, x;
    std::cin >> n;
    for (int i = 1; i < n; i++) {
        std::cin >> x;
        sum += x;
    }
    std::cout << n * (n + 1) / 2 - sum;
    return 0;
}