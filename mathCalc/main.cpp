
#include "Headers.h"

int main()
{
	Math object;

	std::cout << object.findMax() << std::endl;
	std::cout << object.findMin()<< std::endl;
	std::cout << object.findMean()<< std::endl;
	std::cout << object.findMedian() << std::endl;

	/*std::vector<double> m_data1;
	m_data1.push_back(3.28);
	m_data1.push_back(7.69);
	std::vector<double> *m_data2 = &m_data1;
	std::vector<double> m_data = *m_data2;*/
	return 0;
}