#include <iostream>

int main(int argc, char const *argv[])
{
	int n;
	std::cin>>n;
	int temp=2,sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += temp;
		temp = 10*temp+2;
	}
	std::cout<<sum;
	return 0;
}