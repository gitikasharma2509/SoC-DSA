#include<iostream>
using namespace std;

int main(){
    cin>>noskipws;
    int maxi = 0;
    int count = 1;
    char c = 0;
    char pre = 0;
    while(c != 10){
        cin>>c;
        if(pre == 0){
            pre = c;
            continue;
        }
        if(pre == c){
            count++;
        }
        else{
            count = 1;
        }
        pre = c;
        maxi = max(count, maxi);
    }
    cout<<maxi<<endl;
    return 0;
}