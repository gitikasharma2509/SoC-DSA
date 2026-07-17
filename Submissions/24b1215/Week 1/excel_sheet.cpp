#include <iostream>
#include <string>
using namespace std;

int main() {

    int n;
    cin >> n;

    while(n--) {

        string s;
        cin >> s;

        // Checking if format is RXCY type
        if(s[0] == 'R' && isdigit(s[1]) && s.find('C') != string::npos) {

            int i = s.find('C');

            // row number
            string row = s.substr(1, i-1);

            // column number
            int col = stoi(s.substr(i+1));

            string letters = "";

            // converting number to letters
            while(col > 0) {

                col--;

                char ch = 'A' + (col % 26);

                letters = ch + letters;

                col /= 26;
            }

            cout << letters << row << endl;
        }

        // for BC23 type
        else {

            int i = 0;
            int col = 0;

            // converting letters to number
            while(isalpha(s[i])) {

                col = col * 26 + (s[i] - 'A' + 1);

                i++;
            }

            string row = s.substr(i);

            cout << "R" << row << "C" << col << endl;
        }
    }
}