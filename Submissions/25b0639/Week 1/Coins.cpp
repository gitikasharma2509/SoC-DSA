#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, k;
        cin >> n >> k;

        if (k % 2 == 0) {
            if (n % 2 == 0)
                cout << "YES"<<endl;
            else
                cout << "NO" << endl;
        }
        if (k % 2 != 0){
           
            if (n%2 == 0 || n>=k)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}