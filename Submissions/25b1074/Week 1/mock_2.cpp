#include <iostream>
#include <string>
#include <cctype>

using namespace std;

bool isExcel(string cell) {
    long long int i = 0;

    // first part must be letters
    while (i < cell.length() && isalpha(cell[i])) {
        i++;
    }

    // must have at least one letter
    if (i == 0) return false;

    // second part must exist and be all digits
    if (i == cell.length()) return false;

    while (i < cell.length()) {
        if (!isdigit(cell[i])) {
            return false;
        }
        i++;
    }

    return true;
}
string convert(string cell){
    string result = "";
    long long int len = cell.length();
    //EXCEL
    if(isExcel(cell)){
        string column = "";
        string row = "";
        for(long long int i = 0; i < len; i++){
            if(isdigit(cell[i])){
                row += cell[i];
            } else {
                column += cell[i];
            }
        }
        // Convert column to number
        long long int colNum = 0;
        for(long long int i = 0; i < column.length(); i++){
            colNum = colNum * 26 + (column[i] - 'A' + 1);
        }
        result = "R" + row + "C" + to_string(colNum);
    }
    //RCXY to excel
    else{
        long long int rIndex = cell.find('R');
        long long int cIndex = cell.find('C');
        string row = cell.substr(rIndex + 1, cIndex - rIndex - 1);
        string col = cell.substr(cIndex + 1);
        long long int colNum = stoi(col);
        string column = "";
        while(colNum > 0){
            colNum--;
            column += char('A' + (colNum % 26));
            colNum /= 26;
        }
        string revcol = "";
        for(long long int i = column.length() - 1; i >= 0; i--){
            revcol += column[i];
        }
        result = revcol + row;
    }
    return result;
}

int main() {
    long long int n;
    cin >> n;

    for(long long int i = 0; i < n; i++){
        string cell;
        cin >> cell;
        cout << convert(cell) << endl;
        
    }
}