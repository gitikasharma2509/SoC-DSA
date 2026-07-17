#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n - 1);
    bool b = false;
    for (int i = 0; i < n - 1;i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (int i = 0;i<n-1;i++){
        if(v[i]!=i+1) {
            cout << i+1;
            b = true;
            break;
        }
    }
    if(!b)
        cout << n;
}