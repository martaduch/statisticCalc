
#include "Headers.h"

int main()
{
	/*Math object;

	std::cout << object.findMax() << std::endl;
	std::cout << object.findMin()<< std::endl;
	std::cout << object.findMean()<< std::endl;
	std::cout << object.findMedian() << std::endl;*/

	std::vector<double> v1;
	std::vector<double> v2;

	v1.push_back(3.28);
	v1.push_back(7.69);
	v1.push_back(6);
	v1.push_back(5.8);
	v1.push_back(5.3);

	v2.push_back(4.28);
	v2.push_back(7.49);
	v2.push_back(5.6);
	v2.push_back(6.2);
	v2.push_back(1);

	Wilcoxon test;
	test.performTest(v1, v2);

	/*std::vector<double> m_data1;
	m_data1.push_back(3.28);
	m_data1.push_back(7.69);
	std::vector<double> *m_data2 = &m_data1;
	std::vector<double> m_data = *m_data2;*/
	return 0;
}