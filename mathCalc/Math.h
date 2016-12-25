#pragma once

class Math
{
	std::vector<double> m_sample;
	int m_size;
public:
	Math();
	double findMin();
	double findMax();
	double findMean();
	double findMedian();
	double findStdDev();
};

