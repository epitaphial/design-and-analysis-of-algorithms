#include<iostream>
#include <cstring>
#include <algorithm>
#define MAX_NUM 999
using namespace std;

int jarray[MAX_NUM],dp[MAX_NUM];

int jump(int place)
{
    int times = MAX_NUM;
    if(jarray[place+1] == -1)return 0;
    if(dp[place]>0)return dp[place];
    else{
        int num = jarray[place];
        for (int i = 1; i <= num; i++)
        {
            times = min(times,jump(place+i)+1);
        }  
    }
    return dp[place] = times;
}

int main(int argc, char const *argv[])
{
    int x,n=1;
    memset(dp,-1,sizeof(dp));
    memset(jarray,-1,sizeof(jarray));

    while (cin>>x)
        jarray[n++] = x;
    
    int k = jump(1);
    if (k == MAX_NUM)
        cout<<-1<<endl;
    else
        cout<<k<<endl;
    return 0;
}
