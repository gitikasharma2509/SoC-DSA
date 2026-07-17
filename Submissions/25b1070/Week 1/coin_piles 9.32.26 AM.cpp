#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
 
void solve() {
    int a,b;
    cin>>a>>b;
    if ( (a+b)%3==0 and (2*a-b >= 0) and ((2*a-b)%3==0) and (2*b-a >= 0) and ((2*b-a)%3==0) ) cout<<"YES\n";
    else cout<<"NO\n";
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}