#include <iostream>
#include <math.h>

int main(int argc, char const *argv[])
{
	double distance,carrot,load,dx,tmpcar;
	std::cout<<"distance carrot load dx:"<<std::endl;
	std::cin>>distance>>carrot>>load>>dx;
	for (int i = 0; i <(int)(distance/dx) ; ++i)
	{
		tmpcar = carrot - (1+2*(std::ceil(carrot/load)-1))*dx;
		carrot = tmpcar;
	}
	std::cout<<carrot;
	return 0;
}