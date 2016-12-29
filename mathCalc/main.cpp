
#include "Headers.h"

int main()
{

	std::vector<double> v1;
	std::vector<double> v2;

	v1.push_back(125);
	v1.push_back(132);
	v1.push_back(138);
	v1.push_back(120);
	v1.push_back(125);
	v1.push_back(127);
	v1.push_back(136);
	v1.push_back(139);
	v1.push_back(131);
	v1.push_back(132);
	v1.push_back(135);
	v1.push_back(136);
	v1.push_back(128);
	v1.push_back(127);

	Math object(v1);
	std::cout<< object.findMax() << std::endl;
	std::cout << object.findMean() << std::endl;
	std::cout << object.findStdDev() << std::endl;

	v2.push_back(118);
	v2.push_back(134);
	v2.push_back(130);
	v2.push_back(124);
	v2.push_back(105);
	v2.push_back(130);
	v2.push_back(130);
	v2.push_back(132);
	v2.push_back(123);
	v2.push_back(128);
	v2.push_back(126);
	v2.push_back(140);
	v2.push_back(135);
	v2.push_back(126);

	Wilcoxon test;

	if (!test.performTest(v1, v2))
		std::cout << "Unable to perform test" << std::endl;
	return 0;
}