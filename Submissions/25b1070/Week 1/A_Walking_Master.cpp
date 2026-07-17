#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

void solve() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(d>=b and(d-b)>=(c-a)){
        cout<<(d-b)+(d-b)-(c-a)<<'\n';
    }
    else cout<<-1<<'\n';
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