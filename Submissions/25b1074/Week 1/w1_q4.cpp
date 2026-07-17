#include <iostream>
#include <vector>

using namespace std;

int luck(int n){
    int maxluck = 0, luck = 0;
    //check the digits of n
    vector<int> digits;
    while(n > 0){
        digits.push_back(n % 10);
        n /= 10;
    }

    int size = digits.size();
    int highest = 0, lowest = 9;
    for (int i = 0; i < size; i++){
        highest = max(highest, digits[i]);
        lowest = min(lowest, digits[i]);
    }
    maxluck = highest - lowest;
    return maxluck;
}


int main(){
    int t;
    cin >> t;
    
    for(int i = 0; i < t; i++){
        int l, r;
        int max_luck = 0;
        int luckiest = l;
        cin >> l >> r;
        for (int j = l; j <= min(r, l + 100); j++){
            int currentluck = luck(j);
            if (currentluck >= max_luck){
                luckiest = j;
                max_luck = currentluck;
            }
            if (max_luck == 9){
                break;
            }
        }
    cout << luckiest << endl;
    }
}
