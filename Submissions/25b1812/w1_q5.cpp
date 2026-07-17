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
    unsigned long long n; cin >> n;
    cout << n << " ";
    while (n != 1){
        n = (n%2 == 0)? n/2 : 3*n + 1; 
        cout << n << " ";
    }
    cout << endl;
    return;
}

int main() {
    fast;
    solve();
}