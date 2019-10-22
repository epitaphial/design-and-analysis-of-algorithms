#include <iostream>

int main(int argc, char const *argv[])
{
    int n,sum = 0;
    std::cin>>n;
    for (int i = 0; i < n; i++)
        sum += i + 1;
    int *array = new int[sum];
    int *sumA = new int[sum];
    for (int i = 0; i < sum; i++)
        std::cin>>array[i];
    memcpy(sumA, array, sum * sizeof(int));
    while (sum)
    {
        sum = sum - n;
        for (int i = sum; i < sum + n; i++)
        {
            
        }
        n--;
    }
    
    return 0;
}
