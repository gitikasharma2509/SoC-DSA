#include <iostream>
using namespace std;
 
int main() {
	long long n; long long m ; long long a; 
	cin >> n >> m >> a ;
	
	long long x = (n+a-1)/a;
	long long y = (m+a-1)/a;
	
	cout << x*y << endl;
 
}