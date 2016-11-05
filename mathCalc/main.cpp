#include <iostream>
#include <vector>

#include "Math.h"

int main()
{
	Math object;

	std::cout << object.findMax() << std::endl;
	std::cout << object.findMin()<< std::endl;
	std::cout << object.findMean()<< std::endl;
	return 0;
}