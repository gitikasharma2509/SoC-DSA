#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main() {

    int n;
    cin >> n;

    while(n--) {

        string s, ans = "";
        cin >> s;

        // RxCy format
        if(s[0]=='R' && isdigit(s[1]) && s.find('C') != string::npos) {

            ll x = s.find('C');

            string col = s.substr(x+1);

            ll r = stoll(col);

            while(r > 0) {
                r--;
                char p = 'A' + (r % 26);
                ans = p + ans;
                r /= 26;
            }

            ans += s.substr(1, x-1);

            cout << ans << '\n';
        }

        // Excel format
        else {

            ll sum = 0;
            string row = "";

            for(char ch : s) {

                if(isalpha(ch)) {
                    sum = sum * 26 + (ch - 'A' + 1);
                }
                else {
                    row += ch;
                }
            }

            cout << "R" << row << "C" << sum << '\n';
        }
    }

    return 0;
}