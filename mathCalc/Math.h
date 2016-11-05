#pragma once
#include <vector>

class Math
{
	std::vector<double> m_data;
public:
	Math();
	double findMin();
	double findMax();
	double findMean();
};

