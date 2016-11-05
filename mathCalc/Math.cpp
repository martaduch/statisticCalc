#include "Math.h"
#include <math.h>

#define using namespace std;

Math::Math()
{
	m_data.push_back(5);
	m_data.push_back(3.28);
	m_data.push_back(7.69);
	m_data.push_back(1);

	m_size = m_data.size();
}

double Math::findMin()
{
	double min;
	min = m_data[0];

	for (int i = 0; i <m_size; i++)
	{
		if (m_data[i] < min)
			min = m_data[i];
	}
	return min;
}

double Math::findMax()
{
	double max;

	max = m_data[0];

	for (int i = 0; i < m_size; i++)
	{
		if (m_data[i] > max)
			max = m_data[i];
	}
	return max;
}

double Math::findMean()
{
	double mean;
	double sum = 0;

	for (int i = 0; i < m_size; i++) {
		sum += m_data[i];
	}
	mean = sum / m_size;
	return mean;
}

double Math::findStdDev()
{
	double mean = findMean();
	double sum = 0.0, standardDeviation = 0.0;

	for (int i = 0; i < m_size; ++i)
		standardDeviation += pow(m_data[i] - mean, 2);

	return sqrt(standardDeviation / m_size);
}
