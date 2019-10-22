#include <iostream>

int main(int argc, char const *argv[])
{
    int n;
    std::cout<<"input size n:"<<std::endl;//n*n
    std::cin>>n;
    int **array = new int *[n];
    for (int i = 0; i < n; i++)
        array[i] = new int[n];
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    {
        std::cin>>array[i][j];
    }
    int numTofind;
    std::cout<<"please input the number to find:"<<std::endl;
    std::cin>>numTofind;
    int i,j;
    i = 0;
    j = n-1;
    if (numTofind<array[0][0]||numTofind>array[j][j])
    {
        std::cout<<"can\'t find the number!"<<std::endl;
        return 0;
    }
    
    while (i>=0 && j>=0)
    {
        if (numTofind == array[i][j])
        {
            std::cout << "row:"<<i<<" col:"<<j<< std::endl;
            return 0;
        }
        else if (numTofind > array[i][j])
            i++;
        else if (numTofind < array[i][j])
            j--;
    }
    std::cout<<"can\'t find the number!"<<std::endl;
    return 0;
}
