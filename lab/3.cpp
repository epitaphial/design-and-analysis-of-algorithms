#include<iostream>
#include <cstring>
#include <algorithm>
#define MAX_NUM 999
using namespace std;


int main(int argc, char const *argv[])
{
    int x,n=1,arrayN[MAX_NUM],left=0,right=0,bigest=0,countN=0;
    memset(arrayN,-1,sizeof(arrayN));
    while (cin>>x)
        arrayN[n++] = x;
    right = n;
    for (int i = 1; i <= n; i++)
    {
        if(arrayN[i]>bigest)
            bigest = arrayN[i];
    }
    
    for (int i = 1; i <= bigest; ++i)
    {
        for (int i = 1; i <= n; i++)
            if(arrayN[i]>0)
                {left = i;break;}
        for(int i = n;i>=1;i--)
            if(arrayN[i]>0)
                {right = i;break;}
        for (int i = left; i <= right; i++)
        {
            if(arrayN[i]<=0)
                countN++;
        }
        for (int i = 1; i <=n; i++)
            arrayN[i]--;
    }
    cout<<countN;
    return 0;
}
