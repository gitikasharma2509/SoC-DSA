#include <iostream>
#include <string>
#include<algorithm>
#include <vector>
using namespace std;
int main(){
    int t,l,r,luckiness;
    cin>>t;
    vector<int> lucky_no(t);
    for(int p=0;p<t;p++){
        cin>>l>>r;
        lucky_no[p]=0;
        luckiness=0;
        int diff=0;
        for(int i=l;i<=r;i++){
            string s=to_string(i);
            int gdigit=*max_element(s.begin(),s.end());
            int ldigit=*min_element(s.begin(),s.end());
            diff=gdigit-ldigit;
            if(luckiness<=diff){
                luckiness=diff;
                lucky_no[p]=i;
            }
            
            if(luckiness==9) break;
        }
    }
    for(int x : lucky_no)
        cout << x << '\n';
}