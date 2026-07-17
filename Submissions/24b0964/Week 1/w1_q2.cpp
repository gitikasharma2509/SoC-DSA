#include <iostream> 
#include <string>
using namespace std;

int main(){
    string str;
    cin>>str;

    char prev = str[0];
    long long maxi = 0, count = 0;
    for(auto c : str){
        // cout<<c<<'\n';
        if(c==prev) count+=1;
        else{
            count = 1;
        }
        maxi = max(maxi, count);
        // cout<<maxi<<'\n';
        prev = c;
    }

    cout<<maxi<<'\n';
}
