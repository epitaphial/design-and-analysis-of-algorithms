#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_NUM 999

using namespace std;

int n,k;
int fav[MAX_NUM][MAX_NUM],dp[MAX_NUM][MAX_NUM];

//give out sugar from r,the no.n-1's sugar is s
int fatang(int r,int s){
    int res = 0;
    if(r>n) return res;
    if(dp[r][s]>0)return dp[r][s];
    else{
    for (int i = 1; i <=k ; i++)
    {
        if(s == i)continue;
        res = max(fatang(r+1,i)+fav[r][i],res);
    }
    }
    return dp[r][s] = res;
}

int main(int argc, char const *argv[])
{

    cin>>n>>k;
    for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++)
    {
        cin>>fav[i][j];
    }
    memset(dp,-1,sizeof(dp));
    cout<<fatang(1,-1);
    
    return 0;
}
