#include "Headers.h"


Math::Math()
{
	m_sample.push_back(3.28);
	m_sample.push_back(7.69);
	m_sample.push_back(1);
	m_sample.push_back(85);
	m_size = m_sample.size();
}

double Math::findMin()
{
	double min;
	min = m_sample[0];

	for (int i = 0; i < m_size; i++)
	{
		if (m_sample[i] < min)
			min = m_sample[i];
	}
	return min;
}

double Math::findMax()
{
	double max;

	max = m_sample[0];

	for (int i = 0; i < m_size; i++)
	{
		if (m_sample[i] > max)
			max = m_sample[i];
	}
	return max;
}

double Math::findMean()
{
	double sum = 0;

	for (int i = 0; i < m_size; i++) {
		sum += m_sample[i];
	}
	return sum / m_size;
}

double Math::findMedian()
{
	std::sort(m_sample.begin(), m_sample.end());

	if (m_size % 2 == 0)
		return (m_sample[m_size / 2 - 1] + m_sample[m_size / 2]) / 2;
	else
		return m_sample[m_size / 2];
}

double Math::findStdDev()
{
	double mean = findMean();
	double sum = 0, standardDeviation = 0;

	for (int i = 0; i < m_size; ++i)
		standardDeviation += pow(m_sample[i] - mean, 2);

	return sqrt(standardDeviation / m_size);
}
