#include <bits/stdc++.h>
using namespace std;

void veratisum(long a){
    cout << a << " ";
    if(a == 1){
        return;
    }
    else if(a%2 == 0){
        a = a/2;
    }
    else{
        a = 3 * a + 1;
    }
    veratisum(a);
}
int main() {
    long a;
    cin >> a;
    veratisum(a);
}
