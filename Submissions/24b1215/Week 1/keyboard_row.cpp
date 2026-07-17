#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        unordered_set<char> row1 = {
            'q','w','e','r','t','y','u','i','o','p'
        };

        unordered_set<char> row2 = {
            'a','s','d','f','g','h','j','k','l'
        };

        unordered_set<char> row3 = {
            'z','x','c','v','b','n','m'
        };

        vector<string> ans;

        for(string word : words) {

            string lower = word;

            for(char &c : lower) {
                c = tolower(c);
            }

            int row;

            if(row1.count(lower[0]))
                row = 1;
            else if(row2.count(lower[0]))
                row = 2;
            else
                row = 3;

            bool valid = true;

            for(char c : lower) {

                if(row == 1 && !row1.count(c)) {
                    valid = false;
                    break;
                }

                if(row == 2 && !row2.count(c)) {
                    valid = false;
                    break;
                }

                if(row == 3 && !row3.count(c)) {
                    valid = false;
                    break;
                }
            }

            if(valid) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};

int main() {

    vector<string> words = {
        "Hello",
        "Alaska",
        "Dad",
        "Peace"
    };

    Solution s;

    vector<string> ans = s.findWords(words);

    for(string word : ans) {
        cout << word << " ";
    }

    cout << endl;

    return 0;
}