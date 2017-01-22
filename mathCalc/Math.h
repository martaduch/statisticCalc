#pragma once

class Math
{
	std::vector<double> *m_sample;
	double findMin();
	double findMax();
	double findMean();
	double findMedian();
	double findStdDev();
public:
	Math(std::vector<double> &vec);
	void performTest();
};

