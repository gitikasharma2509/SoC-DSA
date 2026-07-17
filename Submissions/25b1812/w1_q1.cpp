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



int main() {
    fast;
    ll n; cin >> n; 
    ll s = (n*(n+1))/2;
    for (ll i= 0; i < n-1 ; i++) {
        ll x; cin >> x;
        s -= x;
    }
    cout << s << endl;
    return 0;
    
}