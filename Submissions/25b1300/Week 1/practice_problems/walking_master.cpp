#include <bits/stdc++.h>
using namespace std;

class coordinate {
    public : 
    long long x;
    long long y;
};

long long minMoves(coordinate c1,coordinate c2) {
    if(c1.x == c2.x && c1.y == c2.y) return 0;
    else if(c1.y==c2.y && c1.x > c2.x) return abs(c1.x-c2.x); 
    else if(c1.x+abs(c1.y-c2.y) < c2.x || c2.y < c1.y) return -1;
    return abs(c1.y-c2.y) + abs(c1.x + abs(c1.y-c2.y) - c2.x);
}

int main() {
    long long t;
    cin >> t;
    vector<coordinate> c1, c2;
    for(long long i=0; i<t; i++){
        coordinate a, b;
        cin >> a.x >> a.y >> b.x >> b.y;
        c1.push_back(a);
        c2.push_back(b);
    }
    for(long long i=0; i<t; i++){
        cout << minMoves(c1[i], c2[i]) << "\n";
    }
    return 0; 
}