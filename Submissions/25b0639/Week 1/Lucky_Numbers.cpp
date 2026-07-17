#include <bits/stdc++.h>
using namespace std;

int lucky (int x){
    int mini = 9;
    int maxi = 0;

    while (x){
       
        int d = x % 10;
        mini = min(mini, d);
        maxi = max(maxi, d);
        x /= 10;
    }

    return maxi - mini;
}

int main() {
    
    int t;
    cin >> t;

    while (t--)
    {
        int l, r;
        cin >> l >> r;

        int ans = l;

        for (int i = l; i <= min(r,l+100); i++)
        {
            if (lucky(i) > lucky(ans))
                ans = i;
        }

        cout << ans << endl;
    }
}