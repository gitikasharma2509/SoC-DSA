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
    string s; cin>> s;
    ll cnt = 1;
    ll x= 1;
    ll n = s.size();
    for (int i = 1; i < n; i++){
        if (s[i] == s[i-1]) x ++;
        else {
            cnt = max(cnt, x);
            x = 1;
        }
    }
    cnt = max(x, cnt);
    cout << cnt; 
}

int main() {
    fast
    solve();

}