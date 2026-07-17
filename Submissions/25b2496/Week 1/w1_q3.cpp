#include <iostream>
using namespace std;

int main()
{
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        long n;
        cin >> n;
        long k;
        cin >> k;
        if (n % 2 == 0)
        {
            cout << "YES" << endl;
        }
        else if (n % 2 == 1 && k % 2 == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            if (n >= k)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
}