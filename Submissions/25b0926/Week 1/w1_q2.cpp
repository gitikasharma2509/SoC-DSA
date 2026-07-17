#include <iostream>
#include <string>
using namespace std;
#include <algorithm>

int main(){
    int count=1,maxsofar=1;
    string dna;
    cin>>dna;
    for(size_t i=1;i<dna.size();i++){
        if(dna[i]==dna[i-1]) {
            count++;
            if (i==dna.size()-1) {
                maxsofar=max(maxsofar,count);
            }
        }
        else {
            maxsofar=max(maxsofar,count);
            count=1;
        }
    }
    cout<<maxsofar<<endl;
}