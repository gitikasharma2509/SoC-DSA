#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <string>


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<char> v;
    string line;
    getline(cin, line);
    for(size_t i=0; i<line.size(); i++) {
        if(line[i] != ' ') {
            v.push_back(line[i]);
        }
    }
    vector<int> max;
    max.push_back(1);
    max.push_back(1);
    int j = 1;
    for(size_t i=1; i< v.size(); i++) {
        if(v[i] == v[i-1]) {
            max[j]= max[j]+1; 
            if(j == 1 && max[1] >= max[0]) {
                max.erase(max.begin());
                j = 0;
            }
        }
        else {
            if(j == 1){
                if(max[1] < max[0]) {
                    max.erase(max.begin()+1);
                }
                j = 0;
            }
            max.push_back(1);
            j=1;
        }
    }
    cout << max[0] << endl;
    return 0;
}