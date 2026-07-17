#include <bits/stdc++.h>
using namespace std;
string numToLet(int colNum){
    string result = "";
    while (colNum > 0){
        colNum--;
        char c = (colNum % 26) + 'A';
        result = c + result;
        colNum /= 26;
    }
    return result;
}
int letToNum(string colStr){
    int result = 0;
    for (char c : colStr){
        result = result * 26 + (c - 'A' + 1);
    }
    return result;
}
int main(){
    int n;
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        bool sys2 = false;
        int C_index = 0;
        for (int i = 1; i < s.length(); i++){
            if (s[i] == 'C' && isdigit(s[i - 1])){
                sys2 = true;
                C_index = i;
                break;
            }
        }
        if (sys2){
            string rowStr = s.substr(1, C_index - 1);
            int col = stoi(s.substr(C_index + 1));
            cout << numToLet(col) << rowStr << endl;
        }
        else{
            int firstDigitPos = 0;
            while (firstDigitPos < s.length() && !isdigit(s[firstDigitPos])){
                firstDigitPos++;
            }
            string colStr = s.substr(0, firstDigitPos);
            string rowStr = s.substr(firstDigitPos);
            cout << "R" << rowStr << "C" << letToNum(colStr) << endl;
        }
    }
    return 0;
}
