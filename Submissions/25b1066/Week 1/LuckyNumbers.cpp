#include<bits/stdc++.h>
using namespace std;

int luckiness(int x){
    if (x == 0)
        return 0;
    int max_digit = 0;
    int min_digit = 9;
    while(x>0){
        int digit = x % 10;
        max_digit = max(max_digit, digit);
        min_digit = min(min_digit, digit);
        x /= 10;
    }
    return max_digit - min_digit;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int l, r;
        cin >> l >> r;
        int best = l;
        for (int x = l; x <= min(r, l + 100); ++x){
            if (luckiness(x) > luckiness(best)){
                best = x;
            }
            if (luckiness(best) == 9)
                break;
        }
        cout << best << endl;
    }
}