#include <iostream>
#include <set>
using namespace std;
int main() {
    int test;cin>>test;
    while(test--){
        int n; cin >>n;
        int arr[100];
        for (int i = 0 ; i < n ; i++){
            cin>> arr[i];
        }
        
        int x = n;
        
        
        for (int i = 0 ; i < n ; i++){
            int l = 0 ; int r = 0;
            for (int k = 0 ; k < n ; k++){
                if(arr[k]<arr[i])
                l++;
                
                else if (arr[k]>arr[i])
                r++;
            }
            x = min(x , max(l,r));
            
            
        }
        cout<< x << endl;
    }
    return 0;
}