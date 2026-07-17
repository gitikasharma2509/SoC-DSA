# include <iostream>
using namespace std;
int main() {
 string dna;
 cin>>dna;
 int n=dna.length();
 int count=1;
 int max=1;
 for(int i=0;i<n-1;i++){
  if(dna[i]==dna[i+1])count++;
  else count=1;
  if(max<count)max=count;

 }
 cout<<max;
}
