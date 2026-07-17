#include <iostream>

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        long long n, k;
        std::cin >> n >> k;
        
        if (n % 2 == 0 || k % 2 != 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}