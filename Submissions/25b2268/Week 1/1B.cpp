#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;

int factor(int x, int p){
    if(x == 0) return 1;
    int count = 0;
    while(x%p == 0){
        count++;
        x /= p;
    }
    return count;
}

int main(){
    int n;
    int zerorow = -1;
    int zerocol = -1;
    cin>>n;
    int matrix[n][n];
    int m2[n][n];
    int m5[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            m2[i][j] = 0;
        }
    }
     for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            m5[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>matrix[i][j];
            int x = matrix[i][j];
            if(x == 0){
                zerorow = i;
                zerocol = j;
                m2[i][j] = 1;
                m5[i][j] = 1;
            }else{
                m2[i][j] = factor(x,2);
                m5[i][j] = factor(x,5);
            }
        }
    }
     
    
   int dp2[n][n];
   int dp5[n][n];
   char par2[n][n];
   char par5[n][n];
   dp2[0][0] = m2[0][0];
   dp5[0][0] = m5[0][0];
   for(int i = 1; i < n; i++){
    dp2[i][0] = dp2[i-1][0] + m2[i][0];
    par2[i][0] = 'D';

    dp5[i][0] = dp5[i-1][0] + m5[i][0];
    par5[i][0] = 'D';
   }
   for(int j = 1; j < n; j++){
    dp2[0][j] = dp2[0][j-1] + m2[0][j];
    par2[0][j] = 'R';

    dp5[0][j] = dp5[0][j-1] + m5[0][j];
    par5[0][j] = 'R';
   }
   for(int i = 1; i < n; i++){
    for(int j = 1; j < n; j++){
        if(dp2[i-1][j] < dp2[i][j-1]){
            dp2[i][j] = dp2[i-1][j] + m2[i][j];
            par2[i][j] = 'D';
        }else{
            dp2[i][j] = dp2[i][j-1] + m2[i][j];
            par2[i][j] = 'R';
        }
        if(dp5[i-1][j] < dp5[i][j-1]){
            dp5[i][j] = dp5[i-1][j] + m5[i][j];
            par5[i][j] = 'D';
        }else{
            dp5[i][j] = dp5[i][j-1] + m5[i][j];
            par5[i][j] = 'R';
        }
    }
   }
   int best = min(dp2[n-1][n-1] , dp5[n-1][n-1]);
    if(zerorow != -1 && best > 1){
        cout<<1<<endl;
        string path;
        for(int i = 0; i < zerorow; i++){
            path += "D";
        }
        for(int i = 0; i < zerocol; i++){
            path += "R";
        }
        for(int i = zerorow; i < n-1; i++){
            path += "D";
        }
        for(int i = zerocol; i < n-1; i++){
            path += "R";
        }
        cout<<path<<endl;
        return 0;
    }
    string path;
    if(dp2[n-1][n-1] < dp5[n-1][n-1]){
        int i = n-1;
        int j = n-1;
        while(i > 0 || j > 0){
            path += par2[i][j];
            if(par2[i][j] == 'D'){
                i--;
            }else{
                j--;
            }
        }
        reverse(path.begin(), path.end());
        cout<<dp2[n-1][n-1]<<endl;
        cout<<path<<endl;
    }else{
         int i = n-1;
        int j = n-1;
        while(i > 0 || j > 0){
            path += par5[i][j];
            if(par5[i][j] == 'D'){
                i--;
            }else{
                j--;
            }
        }
        reverse(path.begin(), path.end());
        cout<<dp5[n-1][n-1]<<endl;
        cout<<path<<endl;
    }

    return 0;
}