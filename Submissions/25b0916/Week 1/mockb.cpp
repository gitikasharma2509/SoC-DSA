#include<iostream>
#include<string>
using namespace std;
bool isRXCY(string s){
    if(s[0] != 'R')
        return false;
    if(s[1]>='A' && s[1]<='Z'){
        return false;
    }
    return s.find('C') != string::npos;
}
int main(){
    int t;
    cin>>t;
    string s;
    for(int k=0;k<t;k++){
        long x=0,y=0;
        string ans="";
    cin>>s;
        if(isRXCY(s)){
            int i=1;
            while(s[i]!= 'C'){
                x = 10*x + (s[i]-'0');
                i++;
            }
            i++;
            while(i<s.size()){
                y = 10*y + (s[i]-'0');
                i++;
            }
            while(y>0){
                y--;
                char ch = 'A' + (y % 26);
                ans = ch + ans;
                y = y/26;
            }
            ans = ans + to_string(x);
        } 
        else{
            int i=0;
            while (i<s.size() && s[i]>='A' && s[i]<='Z')
            {
                y= y*26 + (s[i] - 'A' +1);
                i++;
            }
            while(i<s.size()){
                x= x*10 + (s[i]-'0');
                i++;
            }
            ans = "R";
            ans += to_string(x);
            ans += "C";
            ans += to_string(y);
        }
        cout<<ans<<endl;
}
return 0;
}