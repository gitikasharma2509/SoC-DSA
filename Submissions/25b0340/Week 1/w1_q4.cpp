#include<iostream>
using namespace std;

int luckiness(long long x){
    int mn=9;
    int mx=0;
    while(x > 0){
        int d = x % 10;
        mn = min(mn, d);
        mx = max(mx, d);
        x /= 10;
    }
    return mx - mn;
}
int main(){
    long long N;
    cin>>N;
    for(int j=0;j<N;j++){
        long long l, r;
        cin>>l>>r;
        long long lucky=l;
        int luck=luckiness(l);

        for (long long i=l; i<=min(r, l+100); i++){
            int cur=luckiness(i);
            if(cur>luck){
                luck=cur;
                lucky=i;
            }
        }
        cout<<lucky<<endl;
    }
}