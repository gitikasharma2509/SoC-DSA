#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0);

const int MOD = 1e9 + 7;
const int INF = 1e9;

void solve() {
    ll n, k; cin >> n >> k;
    if (n%2 == 0 || (n-k >= 0 && (n-k)%2 == 0)) cout << "YES" << endl;
    else cout << "NO" << endl;
    
}

int main() {
    fast
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}