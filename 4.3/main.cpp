#include <iostream>
#include <cmath>

int cut(int n,int m,int stick){
    if (stick >= n)
        return 0;
    else if (stick < m)
        return 1 + cut(n,m,2*stick);
    else if(stick > m)
        return 1 + cut(n,m,stick + m);
}

int main(int argc, char const *argv[])
{
    int n,m;
    std::cin>>n>>m;
    std::cout<<cut(n,m,1)<<std::endl;
    return 0;
}