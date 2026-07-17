#include<iostream>
#include<cstring>
using namespace std;

bool isDigit(char c){
	return c>='0' && c<='9' ;
}

bool isLetter(char c){
	return c>='A' && c<='Z' ;
}

bool isRXCY(string s){
	int pos = -1;
	for (int i=0; i < s.size(); i++){
		if(s[i] == 'C'){
			pos =i;
			break;
		}
	}
	if (s[0] != 'R' || pos == -1)
        	return false;

    	if (pos == 1)
        	return false;

    	if (pos == s.size() - 1)
        	return false;

    	for (int i = 1; i < pos; i++) {
        	if (!isDigit(s[i]))
            		return false;
    	}

    	for (int i = pos + 1; i < s.size(); i++) {
        	if (!isDigit(s[i]))
            		return false;
    	}

    	return true;
}

string numberToColumn(int n) {
	string col = "";

    	while (n > 0) {
        	n--;
        	col = char('A' + (n % 26)) + col;
        	n /= 26;
   	}

    	return col;
}

int columnToNumber(string col) {
    	int num = 0;

    	for (char c : col) {
        	num = num * 26 + (c - 'A' + 1);
    	}

    	return num;
}

int main(){
	int t;
	cin >> t;

	while(t--){
		string s;
		cin >> s;

		if(isRXCY(s)){
			int pos = -1;
			for(int i=0; i<s.size(); i++){
				if(s[i]=='C'){
					pos = i;
					break;
				}
			}
			int row = stoi(s.substr(1, pos - 1));
			int col = stoi(s.substr(pos + 1));
			cout << numberToColumn(col) << row << endl;
		}

		else{
			string col = "", row = "";
			for (char c : s) {
                		if (isLetter(c))
                    			col += c;
                		else
                    			row += c;
            		}

            		cout << "R" << row << "C" << columnToNumber(col) << endl;
		}
	}
	return 0;
}


