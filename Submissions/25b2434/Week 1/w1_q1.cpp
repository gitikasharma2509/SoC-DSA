#include<iostream>
using namespace std; 

int main(){
    int n; 
    cin >> n; 
    int a[n + 1] = {0};
    for(int i = 0; i < n - 1; i++){
        int j; 
        cin >> j ;
        a[j] = j ;
    }
    for(int j =1; j < n +1; j++){
        if(a[j] == 0){
            cout << j ;
        }
    }

}