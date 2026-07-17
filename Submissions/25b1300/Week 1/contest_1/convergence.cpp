#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        sort(a.begin(), a.end());
        
        if (a.front() == a.back()) {
            cout << 0 << "\n";
            continue;
        }
        
        int x = n;
        
        for (int T : a) {
            int L = (int)(lower_bound(a.begin(), a.end(), T) - a.begin());
            int R = (int)(a.end() - upper_bound(a.begin(), a.end(), T));
            x = min(x, max(L, R));
        }
        
        for (int i = 0; i < n - 1; i++) {
            if (a[i+1] > a[i] + 1) {
                int L = i + 1, R = n - i - 1;
                x = min(x, max(L, R));
            }
        }
        
        cout << x << "\n";
    }
    return 0;
}