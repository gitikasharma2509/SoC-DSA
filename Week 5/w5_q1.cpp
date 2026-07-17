#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<int> st;
    st.push(-1);

    int best = 0;
    int cnt = 0;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '(') {
            st.push(i);
        }
        else {
            st.pop();

            if (st.empty()) {
                st.push(i);
            }
            else {
                int len = i - st.top();

                if (len > best) {
                    best = len;
                    cnt = 1;
                }
                else if (len == best) {
                    cnt++;
                }
            }
        }
    }

    if (best == 0)
        cout << "0 1\n";
    else
        cout << best << " " << cnt << "\n";

    return 0;
}