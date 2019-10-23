#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> numVect,sumVect;
int amount = 0;

int cmp(int a,int b)
{
    return b < a;
}

void loop(int reqSum,int doneSum,int left){
    if (doneSum == reqSum)
    {
        for(auto iter:sumVect){
            std::cout<<iter<<" ";
        }
        std::cout<<std::endl;
        amount++;
        return;
    }
    if (doneSum > reqSum || left > (int)numVect.size()){
        return;
    }
    for (int i = left; i < (int)numVect.size(); i++)
    {

        doneSum += numVect[i];
        sumVect.insert(sumVect.end(),numVect[i]);
        loop(reqSum,doneSum,i+1);
        doneSum -= numVect[i];
        sumVect.pop_back();
    }
}

int main(int argc, char const *argv[])
{
    int n,sum;
    std::cin>>n>>sum;
    int tempNum;
    for (int i = 0; i < n; i++)
    {
        std::cin>>tempNum;
        numVect.insert(numVect.end(),tempNum);
    }
    std::sort(numVect.begin(),numVect.end(),cmp);
    loop(sum,0,0);
    std::cout <<"the number of schemes:"<<amount << std::endl;
    return 0;
}
