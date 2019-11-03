#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_NUM 9999

int G,P,N,plan;
int costI[MAX_NUM],feedP[MAX_NUM],dp[MAX_NUM][MAX_NUM];

using namespace std;


int choose(int s,int remain){
    if(dp[s][remain]!=-1)
        return dp[s][remain];
    int res;
    if(s == N)
    {
        res = 0;
    }
    if(remain < costI[s])
        res = choose(s+1,remain);
    else
    {
        res = max(choose(s+1,remain),choose(s+1,remain - costI[s])+feedP[s]);
    }
    return dp[s][remain] = res;
}

int main(int argc, char const *argv[])
{
    cin>>G>>P>>N;
    for (int i = 1; i <= N; i++)
        cin>>costI[i];

    for (int i = 1; i <= N; i++)
        cin>>feedP[i];

    memset(dp,-1,sizeof(dp));
    choose(1,G);
    plan = 0;
    for (int i = 1; i <= N; i++)
    {
        if(dp[i][G]>=P)
            plan++;
    }
    cout<<plan;

    return 0;
}
