#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,count;
    count = 0;
    cin >> n;
    unordered_map<int, int> numbers;
    for(int i=1; i<n+1; i++) {
        int x;
        cin >> x;
        numbers[x] = i;
    }
    for(int i=1; i<n+1; i++) {
        if(numbers[i] > numbers[i+1]) {
            count++;
        }
    }
    cout << count << "\n";
    return 0;
}