#pragma once
#include <vector>

class Math
{
	std::vector<double> m_data;
	int m_size;
public:
	Math();
	double findMin();
	double findMax();
	double findMean();
	double findStdDev();
};

