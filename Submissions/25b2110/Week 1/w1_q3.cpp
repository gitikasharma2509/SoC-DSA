# include <iostream>
using namespace std;

int main() {
int t;
cin>>t;
long long n[t];
long long k[t];

for(int i=0;i<t;i++){
  cin>>n[i];
  cin>>k[i];
}

  for(int i=0;i<t;i++){
    if(n[i]%2==0 || k[i]%2!=0){ //if n is even coin 2 will look for it and if nis odd and
                                                                  //also k is odd then it'll be valid
      cout<<"yes\n";
    }else cout<<"no\n";



    }


}
