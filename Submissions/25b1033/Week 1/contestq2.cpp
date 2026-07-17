#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
int fc(int x, int p){
    if(x==0)return 1e9;
    int count=0;
    while(x%p==0){
        x=x/p;
        count++;
    }
    return count;
}
void rp(int x, int y,char p[][1005], string &path){
    if(x==0&&y==0)return;
    if(p[x][y]=='D'){
        rp(x-1,y,p,path);
        path+='D';
    }
    else{
        rp(x,y-1,p,path);
        path+='R';
    }
}
int main(){
    int n,zx=-1,zy=-1;
    cin>>n;
    string path="";
    ll a[n][n],c2[n][n],c5[n][n],r2[n][n],r5[n][n];
    char p2[1005][1005],p5[1005][1005];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j]==0){
                zx=i;zy=j;
            }
            c2[i][j]=fc(a[i][j],2);
            c5[i][j]=fc(a[i][j],5);
            if (i == 0 && j == 0) {
            r2[i][j] = c2[i][j];
            p2[i][j]='x';
            }
            else {
            r2[i][j] = 1e18;

            if (i > 0) {
                if (r2[i - 1][j] + c2[i][j] < r2[i][j]) {
                    r2[i][j] = r2[i - 1][j] + c2[i][j];
                    p2[i][j] = 'D';
                }
            }
            if (j > 0) {
                if (r2[i][j - 1] + c2[i][j] < r2[i][j]) {
                    r2[i][j] = r2[i][j - 1] + c2[i][j];
                    p2[i][j] = 'R';
                    }
                }
            }
            
            if (i == 0 && j == 0) {
                r5[i][j] = c5[i][j];
                p5[i][j]='x';
            }
            else {
                r5[i][j] = 1e18;
                if (i > 0) {
                    if (r5[i - 1][j] + c5[i][j] < r5[i][j]) {
                        r5[i][j] = r5[i - 1][j] + c5[i][j];
                        p5[i][j] = 'D';
                    }
                }
                if (j > 0) {
                    if (r5[i][j - 1] + c5[i][j] < r5[i][j]) {
                        r5[i][j] = r5[i][j - 1] + c5[i][j];
                        p5[i][j] = 'R';
                    }
                }
            }
        }
    }
    ll round=min(r2[n-1][n-1],r5[n-1][n-1]);
    if(zx!=-1&&round>1){
        round=1;
        for(int i=0;i<zx;i++){
            path+='D';
        }
        for(int j=0;j<n-1;j++){
            path+='R';
        }
        for(int i=zx;i<n-1;i++){
            path+='D';
        }
    }
    else{
        if(r2[n-1][n-1]<r5[n-1][n-1]){
            rp(n-1,n-1,p2,path);
        }
        else{
            rp(n-1,n-1,p5,path);
        }
    }
    cout<<round<<'\n';
    cout<<path;

}