#include "Headers.h"


Math::Math(std::vector<double> &vec)
{
	m_sample = &vec;
}

double Math::findMin()
{
	double min;
	min = (*m_sample)[0];

	for (int i = 0; i < m_sample->size(); i++)
	{
		if ((*m_sample)[i] < min)
			min = (*m_sample)[i];
	}
	return min;
}

double Math::findMax()
{
	double max;

	max = (*m_sample)[0];

	for (int i = 0; i < m_sample->size(); i++)
	{
		if ((*m_sample)[i] > max)
			max = (*m_sample)[i];
	}
	return max;
}

double Math::findMean()
{
	double sum = 0;

	for (int i = 0; i < m_sample->size(); i++) {
		sum += (*m_sample)[i];
	}
	return sum / m_sample->size();
}

double Math::findMedian()
{
	std::sort(m_sample->begin(), m_sample->end());

	if (m_sample->size() % 2 == 0)
		return ((*m_sample)[m_sample->size() / 2 - 1] + (*m_sample)[m_sample->size() / 2]) / 2;
	else
		return (*m_sample)[m_sample->size() / 2];
}

double Math::findStdDev()
{
	double mean = findMean();
	double sum = 0, standardDeviation = 0;

	for (int i = 0; i < m_sample->size(); ++i)
		standardDeviation += pow((*m_sample)[i] - mean, 2);

	return sqrt(standardDeviation / m_sample->size());
}

void Math::performTest()
{
	std::cout << "calculated data: " << std::endl;
	std::cout << "minimum: " << findMin() << std::endl;
	std::cout << "maximum: " << findMax() << std::endl;
	std::cout << "mean: " << findMean() << std::endl;
	std::cout << "median: " << findMedian() << std::endl;
	std::cout<< "standard deviation: " << findStdDev() << "\n \n ";
}