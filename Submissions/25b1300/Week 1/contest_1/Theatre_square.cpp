#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m, a;
    cin >> n >> m >> a;
    long long tilesAlongLength, tilesAlongWidth;
    if(n % a == 0 && m % a == 0){
        tilesAlongLength = n / a;
        tilesAlongWidth = m / a;
    } else {
        tilesAlongLength = (n / a) + 1;
        tilesAlongWidth = (m / a) + 1;
    }

    cout << tilesAlongLength * tilesAlongWidth << "\n";
    return 0;
}  