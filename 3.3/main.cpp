#include <iostream>

int ifok(int number,int remain){
	if(number%remain == 0){
		if(remain == 1)
			return 1;
		number = number/10;
		ifok(number,remain-1);
	}
	else
		return 0;
}

int main(int argc, char const *argv[])
{
	for (int i = 999999999; i >100000000; i-=9)
	{
		if (ifok(i,9)==1)
			std::cout<<i<<std::endl;
	}
	return 0;
}