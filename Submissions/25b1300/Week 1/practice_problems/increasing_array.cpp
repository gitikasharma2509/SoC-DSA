#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    vector<long long> numbers;

    for(long long i=0; i<n; i++) {
        long long x;
        cin >> x;
        numbers.push_back(x);
    }
    long long count = 0;
    for(long long i=1;i<n;i++){
        if(numbers[i] >= numbers[i-1]) continue;
        else {
            count += numbers[i-1] - numbers[i];
            numbers[i] = numbers[i-1];
        }
    } 
    cout << count << "\n";
    return 0;
}