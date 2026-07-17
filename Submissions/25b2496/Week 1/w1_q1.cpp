#include <iostream>
#include <vector>
 
int main(void)
{
    int len;
    std::cin >> len;
    std::vector<int> numbers(len);
    int sum = 0;
    int sum2 = 0;
    for (int i = 0; i < len; i++)
    {
        std::cin >> numbers[i];
        sum = sum + i;
        sum2 = sum2 + numbers[i];
    }
    sum += len;
    std::cout << (sum - sum2) << std::endl;
}