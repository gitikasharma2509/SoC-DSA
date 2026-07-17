#include <iostream>
using namespace std;
 
int main() {
	long long n,m;
	cin >> n;
	cin >> m;
	long long a;
	cin >> a;
	long long length = (n%a == 0) ? n/a : n/a + 1;
	long long breath = (m%a == 0) ? m/a : m/a + 1;
	long long area = length * breath;
	cout << area;
 
}
