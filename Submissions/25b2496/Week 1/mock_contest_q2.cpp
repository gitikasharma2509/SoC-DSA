#include <iostream>
#include <string>
using namespace std;
 
void func1 (string str, int i) {
    string row = str.substr(1, i-1);
    int col = stoi(str.substr(i+1,str.length()));
    string alpha = "";
    char start = 'A';
    while(col > 0){
        col--;
        alpha += (start + col%26);
        col = col / 26;
    }
    string rev;
    for(int i = 1; i <= alpha.length(); i++){
        rev += alpha[alpha.length() - i];
    }
    rev += row;
    cout << rev << endl;
}
 
void func2(string code){
    int i = 0;
    while(code[i]>= 'A' && code[i] <= 'Z'){
        i++;
    }
    string col = code.substr(0, i);
    string row = code.substr(i, code.length());
    int columns = 0;
    for(int i = 0; i < col.length(); i++){
        columns *= 26;
        columns += col[i] - 'A' + 1;
    }
    string answer = 'R' + row + 'C' + to_string(columns); 
    cout <<answer<< endl;
}
 
int main() {
    int n;
    cin >> n;
    while(n > 0){
        string code;
	    cin >> code;
	    bool chal = true;
	    if(code[0] =='R'){
	        if(code[1] >= '0' && code[1] <= '9'){
	            int i = 2;
	            while(chal){
	                if(code[i] == 'C'){
	                    func1(code,i);
	                    chal = false;
	                }
	                else{
	                    if(i >= code.length()){
	                       break;
	                    }
	                    i++;
	                };
	            }    
	        }
	    }
	    if(chal == true) func2(code);
	    n--;
    };
}
