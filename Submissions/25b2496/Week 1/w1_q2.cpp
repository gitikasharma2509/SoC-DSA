#include <iostream>
using namespace std;
int main(void)
{
    int max = 0;
    int current = 0;
    char first;
    cin >> first;
    char second;
    while (cin.get(second))
    {
        if (first == second)
        {
            current += 1;
        }
        else
        {
            current += 1;
            if (current > max)
            {
                max = current;
            }
            current = 0;
        }
        first = second;
    }
    if (first == second)
    {
        if (current > max)
        {
            current += 1;
            max = current;
        }
    }
    std::cout << max << std::endl;
}