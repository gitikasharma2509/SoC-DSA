#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

string changetorc(string s){
    int i=0,c=0;
    string ans="R";
    while(s[i]<='Z' and s[i]>='A') c=c*26+s[i++]-'A'+1;
    while(s[i]) ans+=s[i++];
    ans+="C";
    ans+=to_string(c);
    return ans;
}
string changetoa1(string s){
    string s1="",s2="";
    int i=1,r=0,c=0;
    while(s[i]!='C') s2+=s[i++];
    i++;
    while(s[i]) c=c*10+s[i++]-'0';
    while(c){
        if(c%26!=0) s1= char(c%26-1+'A')+s1;
        else {
            s1= string(1, 'Z') + s1;
            c-=26;
        }
        c/=26;
    }
    s1+=s2;
    return s1;
}
bool checkRxCy(string s){
    bool a=false;
    for (auto k:s){
        if('C'==k) a=true;
    }
    return s[0]=='R' and s[1]<='9' and s[1]>='0' and a;
}
void solve() {
    string s;
    cin>>s;
    if(checkRxCy(s)) {
        cout<<changetoa1(s)<<'\n';
    }
    else cout<<changetorc(s)<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}