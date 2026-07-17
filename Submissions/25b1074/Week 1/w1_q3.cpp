#include <iostream>

using namespace std;

bool isPossible(long long int n, long long int k){
    return (n % 2 == 0 || (n - k) >= 0 && (n - k) % 2 == 0);
}

int main(){
    long t;
    cin >> t;

    for(long i = 0; i < t; i++){
        long long int n, k;
        cin >> n >> k;

        if(isPossible(n, k)){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

}