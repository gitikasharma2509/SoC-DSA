#include <iostream>
using namespace std;

int lucky(int x){
    int min=9;
    int max=0;
    while(x){
        if(x%10>max)max=x%10;
        if(x%10<min)min=x%10;
        x=x/10;
    }
    return max-min;


}
int main(){
int t;
cin>>t;
int l[t],r[t];
for(int i=0;i<t;i++){
    cin>>l[i]>>r[i];
}

for(int i=0;i<t;i++){
    if(r[i]-l[i]>=100){

        for(int j=0;j<100;j++){
            int k=lucky(l[i]+j);
            if(k==9){cout<<l[i]+j<<endl;
                break;
        }
    }


}else{
         int max=0;
        int number;
         for(int j=0;j<=r[i]-l[i];j++){
        int k=lucky(l[i]+j);


                             if(k>=max){max=k;
                                  number=l[i]+j;
                             }




                   }

                cout<<number<<endl;

  }


}
}
