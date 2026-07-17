#include <iostream>

using namespace std;

int main() {
    long long int m, n, a;
    cin >> m >> n >> a;

    long long int x = 1, y = 1;
    if (m % a == 0){
        x = m / a;
    }
    else{
        x = m / a + 1;
    }
    if (n % a == 0){
        y = n / a;
    }
    else{
        y = n / a + 1;
    }
    cout << x * y << endl;

}