#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

void solve() {
    int n,k;
    cin>>n>>k;
    if(n%2!=0 and k%2==0){
        cout<<"NO\n";
    }
    else cout<<"YES\n";
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