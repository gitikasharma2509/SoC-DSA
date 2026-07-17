#include <bits/stdc++.h>
using namespace std;

struct testcase{
   long long n;
   long long k;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long noOfTestCases;
    cin >> noOfTestCases;
    vector<testcase> v;
    for(long long i=0; i<noOfTestCases; i++) {
        testcase t;
        cin >> t.n >> t.k;
        v.push_back(t);
    }
    int k;
    for(long long i=0; i<noOfTestCases; i++) {
        if(v[i].n % 2 == 0 || v[i].k == 1 || v[i].n % v[i].k ==0) {
            cout << "YES\n";
            continue;
        }
        else {
            k=0;
            for(long long j=v[i].n/v[i].k; j>0; j--) {
                    if((v[i].n - j*v[i].k) % 2 == 0) {
                        cout << "YES\n";
                        k = 1;
                        break;
                    }
        }
            if(k == 0) {
                cout << "NO\n";
            }
        }
    }
    return 0;
}