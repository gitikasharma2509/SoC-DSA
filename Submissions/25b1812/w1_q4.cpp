#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0);

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
   ll l, r; cin >> l >> r;
   if (r-l + 1 >= 100){
    ll n1 = (l/100) * 100 + 90;
    ll n2 =  (l/100 + 1) * 100 + 90;
    if (n1 > l) {cout << n1 << '\n';return;}
    else {cout << n2 << '\n'; return;}
   } 
   ll maxdiff = 0;
   ll num = l;
   for (ll i = l; i <= r; i++){
    ll n = i;
    ll maxd = 0, mind = 9;
    while (n > 0 ){
        maxd = max(maxd, n%10);
        mind = min(mind, n%10);
        n /= 10;
    }
    if (maxd - mind > maxdiff){
        num = i;
    }
    maxdiff = max(maxdiff, maxd - mind);
   }
   cout << num <<'\n';
   return;
}

int main() {
    fast
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}