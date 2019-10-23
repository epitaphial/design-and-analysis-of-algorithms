#include <iostream>
#include <vector>
#include <algorithm>

int cmp(double a,double b)
{
    return b < a;
}

int main(int argc, char const *argv[])
{
    int m,n,k;
    std::cin>>m>>n>>k;
    std::vector<double> challenger_power;
    double temp_power;
    for (int i = 0; i < m*n; i++)
    {
        std::cin>>temp_power;
        challenger_power.insert(challenger_power.end(),temp_power);
    }
    std::sort(challenger_power.begin(),challenger_power.end(),cmp);    
    double **challenger_queue = new double*[n];
    for (int i = 0; i < n; i++)
    {
        challenger_queue[i] = new double[m];
    }
    for (int i = 0; i < m*n; i++)
    {
        //std::cout << challenger_power[i] << std::endl;
        if(i < n*k)
            challenger_queue[i/k][i%k] = challenger_power[i];
        else
            challenger_queue[(i-n*k)/(m-k)][(i-n*k)%(m-k)+k] = challenger_power[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout<<challenger_queue[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    return 0;
}