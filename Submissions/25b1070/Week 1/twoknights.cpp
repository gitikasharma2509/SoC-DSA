#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

void solve(int n) {
    int ans=0;
    if(n<5){
        if (n==1) ans=0;
        if (n==2) ans=6;
        if (n==3) ans=28;
        if (n==4) ans=96;
        cout<<ans<<'\n';
        return ;
    }
    else cout<<n*n*n*(n+1)/2-5*n*n+6*n-(3*n*n-10*n+12)+(3*n*n-4*n+4)-(n*n*(n-1))/2<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i=1;i<n+1;i++) solve(i);

    return 0;
}