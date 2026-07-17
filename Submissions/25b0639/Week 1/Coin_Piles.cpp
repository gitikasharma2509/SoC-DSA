#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--) {
        long long a, b;
        cin >> a >> b;

        long long total = a + b;
        long long small = min(a, b);
        long long large = max(a, b);

        if(total % 3 == 0 && large <= 2 * small)
            cout << "YES" <<endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}