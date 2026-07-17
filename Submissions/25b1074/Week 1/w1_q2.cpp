#include <iostream>
#include <string>

using namespace std;

int main(){

    string dna;
    cin >> dna;

    int maxrep = 1, rep = 1;

    for(int i = 1; i < dna.length(); i++){
        if(dna[i] != dna[i - 1]){
            rep = 1;
        }
        else{
            rep++;
        }
        maxrep = max(maxrep, rep);
    }

    cout << maxrep << endl;
    
}