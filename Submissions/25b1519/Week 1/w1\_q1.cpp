#include <iostream>
using namespace std;

int main() {
long long n;
cin >> n;
long long total = n*(n+1)/2;
long long x;
 
for (int i = 0; i < n-1; i++)
{   cin >> x;
    total -=x;
}
    cout<< total;
    return 0;
}