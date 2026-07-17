#include <iostream>
#include <string>
using namespace std;
int main(){
    string dna_seq;
    cin>>dna_seq;
    int max_len=1,curr_len=1;
    for(int i=1;i<dna_seq.length();i++){
        if(dna_seq[i]==dna_seq[i-1]){
            curr_len++;
            if(curr_len>max_len){
                max_len=curr_len;
            }
        }
        else{
            curr_len=1;
        }
    }
    cout<<max_len;
}