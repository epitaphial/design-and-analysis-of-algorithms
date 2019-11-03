//authored by wgmmmmm
#include <iostream>
#include <algorithm>
#include <cstring>
#define MAX_NUM 99999

using namespace std;

int banjing3[MAX_NUM],banjing15[MAX_NUM];
int dp[MAX_NUM];
int cost[3];
int villege[MAX_NUM];

int main()
{
  int n = 0;
  int x;
  while(cin >> x)
    villege[++n] = x;
  for(int i=0; i<3; ++i)
    cost[i] = villege[n-2+i];
  n -= 3;

  for(int i=1; i<=n; ++i)
    for(int j=i; j>=1; --j)
    {
      if(villege[i] - villege[j] <= 6)
        banjing3[i] = j;
      else
        break;
    }

  for(int i=1; i<=n; ++i)
    for(int j=i; j>=1; --j)
    {
      if(villege[i] - villege[j] <= 30)
        banjing15[i] = j;
      else
        break;
    }

  dp[0] = 0;
  for(int i=1; i<=n; ++i)
  {
    dp[i] = dp[i-1] + cost[0];
    dp[i] = min(dp[i], dp[banjing3[i]-1] + cost[1]);
    dp[i] = min(dp[i], dp[banjing15[i]-1] + cost[2]);
  }

  cout << dp[n] << endl;

  return 0;
}
