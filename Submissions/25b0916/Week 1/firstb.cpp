#include<iostream>
using namespace std;
typedef long long ll;
int count(ll x,int y){
    int cnt = 0;
    while(x && x % y == 0){
        cnt++;
        x /= y;
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;
    ll a[n][n];
    ll two[n][n];
    ll five[n][n];
    char p2[n][n];
    char p5[n][n];
    int zx = -1, zy = -1;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            cin >> a[i][j];

            if(a[i][j] == 0){
                zx = i;
                zy = j;
                a[i][j] = 1;
            }
        }
    }
    two[0][0] = count(a[0][0],2);
    five[0][0] = count(a[0][0],5);

    for(int i=1;i<n;i++){
        two[i][0] = two[i-1][0] + count(a[i][0],2);
        five[i][0] = five[i-1][0] + count(a[i][0],5);
        p2[i][0] = 'D';
        p5[i][0] = 'D';
        two[0][i] = two[0][i-1] + count(a[0][i],2);
        five[0][i] = five[0][i-1] + count(a[0][i],5);
        p2[0][i] = 'R';
        p5[0][i] = 'R';
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(two[i-1][j]<two[i][j-1]){
                two[i][j] = two[i-1][j]+count(a[i][j],2);
                p2[i][j] = 'D';
            }
            else{
                two[i][j] = two[i][j-1]+count(a[i][j],2);
                p2[i][j] = 'R';
            }
            if(five[i-1][j]<five[i][j-1]){
                five[i][j] = five[i-1][j]+count(a[i][j],5);
                p5[i][j] = 'D';
            }
            else{
                five[i][j] = five[i][j-1]+count(a[i][j],5);
                p5[i][j] = 'R';
            }
        }
    }
    int ans = min(two[n-1][n-1],five[n-1][n-1]);
    if(zx != -1 && ans > 1){

        cout << 1 << "\n";

        for(int i=0;i<zx;i++) cout << 'D';
        for(int j=0;j<zy;j++) cout << 'R';
        for(int i=zx;i<n-1;i++) cout << 'D';
        for(int j=zy;j<n-1;j++) cout << 'R';

        cout << "\n";
        return 0;
    }
    char path[2*n];
    int k=0;
    int i=n-1;
    int j=n-1;

    if(two[n-1][n-1]<five[n-1][n-1]){
        cout<<two[n-1][n-1]<<"\n";
        while (i||j)
        {
            path[k++] = p2[i][j];
            if(p2[i][j] == 'D') i--;
            else j--;
        }
        
    }
    else{
        cout<<five[n-1][n-1]<<"\n";
        while(i||j){
            path[k++] = p5[i][j];
            if(p5[i][j] == 'D') i--;
            else j--;
        }
    }
    for(int t=k-1;t>=0;t--)
        cout << path[t];

    cout << "\n";

    return 0;
}