#include <iostream>
#include <map>
#include <vector>

int main(int argc, char const *argv[])
{
    std::map<int,int> numMap;
    int n;//read numbers of amount 'n'
    std::cout<<"input the amount of num:"<<std::endl;
    std::cin>>n;
    std::vector<std::pair<int,int>> numVec;
    numVec.insert(numVec.begin(),std::make_pair(0,0));
    int temp; 
    for (int i = 0; i < n; i++)
    {
        std::cin>>temp;
        if(numMap.find(temp)!=numMap.end())
            numMap[temp]++;
        else
            numMap[temp]=1;
    }
    std::map<int,int>::iterator iter;
    for(iter=numMap.begin();iter!=numMap.end();iter++)
    {

        if(iter->second > numVec[0].second)
        {
            numVec.clear();
            numVec.insert(numVec.begin(),std::make_pair(iter->first,iter->second));
        }
        else if(iter->second == numVec[0].second)
        {
            numVec.insert(numVec.begin(),std::make_pair(iter->first,iter->second));
        }
        //std::cout<<iter->first<<" "<<iter->second<<std::endl;
    }
    for(auto it:numVec)
        std::cout<<"The mode is "<<it.first<<"and the times are "<<it.second<<std::endl;
    return 0;
}
