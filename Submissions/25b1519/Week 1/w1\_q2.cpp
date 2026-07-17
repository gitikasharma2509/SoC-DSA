#include <iostream>
using namespace std;

int main(){
long long currlen=1;
long long maxlen=1;
 string s;
 cin >> s;
for (int i = 0; i < s.length()-1; i++)
{   if (s[i+1]==s[i])
{   
    currlen++;
} else {
    currlen=1;
}
    if (currlen > maxlen)
    {
       maxlen = currlen;
    }
}
    cout << maxlen;
    return 0;
}