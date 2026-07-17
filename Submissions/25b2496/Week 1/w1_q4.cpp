#include <bits/stdc++.h>
#include <string>
 
using namespace std;
 
int luck(string t){
    int max = -1;
    int min = 10;
    int len = t.length();
    for(int i = 0; i < len; i++){
        int temp = t[i] - '0';
        if(max != 9 && temp > max){
            max = temp;
        }
        if(min != 0 && temp < min){
            min = temp;
        }
    }
    return max - min;
}
 
int main() {
    int t;
    cin >> t;
    for(int a = 0; a < t; a++){
        int l,r;
        cin >> l >> r;
        int max_luck = -1;
        int num;
        for(int i = l; i <= r; i++){
            int tt = luck(to_string(i));
            if(tt > max_luck){
                max_luck = tt;
                num = i;
            }
            if (max_luck == 9){
                break;
            }
        }
        cout << num << endl;
    }
}
