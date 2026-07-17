#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;

int no_of(int n,int p){
    if(n==0) return INF;
    int i=0;
    while(n){
        if(n%p==0){
            i++;
            n/=p;
            continue;
        }
        break;
    }
    return i;
}

pair<int,string> least2(vector<vector<pair<int,int>>> &v,int m,int n,int N){
    if(m==1 and n==1){
        return {v[N-m][N-n].first,""};
    }
    else if(m==1){
        int fi=0;
        string s="";
        for(int i=n;i>0;i--){
            fi+=v[N-m][N-i].first;
            if(i!=1) s+="R";
        }
        return{fi,s};
    }
    else if(n==1){
        int fi=0;
        string s="";
        for(int i=m;i>0;i--){
            fi+=v[N-i][N-n].first;
            if(i!=1) s+="D";
        }
        return{fi,s};
    }

    auto d1=least2(v,m-1,n,N),r1=least2(v,m,n-1,N);
    int p1={v[N-m][N-n].first+get<0>(d1)},
        p2={v[N-m][N-n].first+get<0>(r1)};

    if(p1<p2){
        return{p1,"D"+get<1>(d1)};
    }
    else return{p2,"R"+get<1>(r1)};   
}

pair<int,string> least5(vector<vector<pair<int,int>>> &v,int m,int n,int N){
    if(m==1 and n==1){
        return {v[N-m][N-n].second,""};
    }
    else if(m==1){
        int fi=0;
        string s="";
        for(int i=n;i>0;i--){
            fi+=v[N-m][N-i].second;
            if(i!=1) s+="R";
        }
        return{fi,s};
    }
    else if(n==1){
        int fi=0;
        string s="";
        for(int i=m;i>0;i--){
            fi+=v[N-i][N-n].second;
            if(i!=1) s+="D";
        }
        return{fi,s};
    }

    auto d1=least5(v,m-1,n,N),r1=least5(v,m,n-1,N);
    int p1={v[N-m][N-n].second+get<0>(d1)},
        p2={v[N-m][N-n].second+get<0>(r1)};

    if(p1<p2){
        return{p1,"D"+get<1>(d1)};
    }
    else return{p2,"R"+get<1>(r1)};   
}

void solve() {
    int n;
    cin>>n;
    bool zero=false;
    pair<int,int> pos;
    vector<vector<pair<int,int>>> v(n, vector<pair<int,int>>(n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int temp;
            cin>>temp;
            if(temp==0) {
                zero=true; 
                pos={i,j};
            }
            v[i][j]={no_of(temp,2),no_of(temp,5)};
        }
        cout<<'\n';
    }
    auto a2=least2(v,n,n,n),a5=least5(v,n,n,n);
    if(min(a2.first,a5.first)>1 and zero){
        string s="";
        for (int i=0;i<pos.first;i++) s+="D";
        for (int i=0;i<n-1;i++) s+="R";
        for (int i=0;i<n-1-pos.first;i++) s+="D";

        cout<<1<<'\n'<<s<<'\n';
        return;
    }
    if(a2.first>a5.first){
        cout<<a5.first<<'\n'<<a5.second<<'\n';
        return;
    }
    else{
        cout<<a2.first<<'\n'<<a2.second<<'\n';
        return;
    }
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}