#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        long long ps = 0;
        long long cur_min = LLONG_MAX;
        for(int i = 1; i <= n; i++) {
            long long a;
            cin >> a;
            ps += a;
            cur_min = min(cur_min, ps / i);
            cout << cur_min;
            if(i < n) cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}