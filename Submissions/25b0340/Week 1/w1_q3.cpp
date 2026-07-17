#include<iostream>
using namespace std;

int main(){
    long long int N;
    cin>>N;

    for(int i=0; i<N; i++){
        long long n; cin>>n;
        long long k; cin>>k;
        if (k % 2 == 0 && n % 2 == 1)
            cout << "NO\n";
        else
            cout << "YES\n";

    }

    return 0;
}