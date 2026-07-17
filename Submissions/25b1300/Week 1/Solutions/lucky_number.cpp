#include <bits/stdc++.h>
using namespace std;

struct testcase{
   long long min;
   long long max;
};

int luckiness(long long n) {
    long long numb=n;
    long long minDigit = n%10;
    long long maxDigit = n%10;
    while(numb != 0){
        minDigit = min(minDigit, numb % 10);
        maxDigit = max(maxDigit, numb % 10);
        numb = numb / 10;
    }
    return maxDigit - minDigit;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int noOfTestCases;
    int p = 0;
    long long luckyNumber;
    cin >> noOfTestCases;
    vector<testcase> v;
    for(int i=0; i<noOfTestCases; i++) {
        testcase t;
        cin >> t.min >> t.max;
        v.push_back(t);
    }
    for(int i=0; i<noOfTestCases; i++) {
        vector<long long> luck;
        luck.push_back(0);
        for(long long j=v[i].max; j>=v[i].min; j--) {
        if(luckiness(j) == 9)  {
            cout << j << "\n";
            p = 1;
            break;
        }
        else if(luckiness(j) > luck[0]) {
            luck.erase(luck.begin());
            luck.push_back(luckiness(j));
            luckyNumber = j;
        }
    }
        if(p == 0) {
            cout << luckyNumber << "\n";
        }
   }
    return 0;
}