#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long t,a,b;
    cin >> t;
    for(long long i=0;i<t;i++) {
        cin >> a >> b;
        long long sum = a + b;
        if(sum % 3 == 0 && min(a, b) * 2 >= max(a, b)) {
            cout << "YES\n";
        } 
        else {
            cout << "NO\n";
        }
    }
    return 0;
}
