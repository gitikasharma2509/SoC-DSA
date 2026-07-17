#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    
    int max_rep = 0;
    int current_rep = 0;
    char last_char = ' ';
    
    for (char c : s) {
        if (c == last_char) {
            current_rep++;
        } else {
            current_rep = 1;
            last_char = c;
        }
        if (current_rep > max_rep) {
            max_rep = current_rep;
        }
    }
    
    std::cout << max_rep << "\n";
    return 0;
}