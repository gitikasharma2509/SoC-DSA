#include <iostream> 
#include <algorithm>
using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        long long l, r; cin>>l>>r;

        if(r-l>=99){
            long long ans = l - (l%100) + 90;
            if(ans<l) ans+=100;
            cout<<ans<<'\n';
            continue;
        }

        long long ans=l, luck=0;

        for(int i=l; i<=r; i++){
            long long mind=9, maxd=0;
            long long temp = i;
            while(temp!=0){
                long long d = temp%10;
                mind = min(mind, d);
                maxd = max(maxd, d);
                temp/=10;
            }
            if(luck<maxd-mind){
                luck = maxd-mind;
                ans = i;
            }
        }

        cout<<ans<<'\n';
    }
}