#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
int lucky(int n){
    if(n==0) return 0;
    int mi=9,ma=0;
    while(n){
        ma=max(ma,n%10);
        mi=min(mi,n%10);
        n/=10;
    }
    return ma-mi;
}
void solve() {
    int l,r,ma=-1,ans;
    cin>>l>>r;
    for(int i=l;i<=r;i++){
        int temp=lucky(i);
        if(temp>ma){
            ma=temp;
            ans=i;
            if(ma==9) {
                cout<<i<<'\n';
                return;
            }
        }
    }
    cout<<ans<<'\n';
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