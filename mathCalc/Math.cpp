#include "Math.h"

#define using namespace std;

Math::Math()
{
	m_data.push_back(5);
	m_data.push_back(3.28);
	m_data.push_back(7.69);
	m_data.push_back(1);
}

double Math::findMin()
{
	double min;
	min = m_data[0];

	for (int i = 0; i < m_data.size(); i++)
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

	for (int i = 0; i < m_data.size(); i++)
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
	int size = m_data.size();
	for (int i = 0; i < size; i++) {
		sum += m_data[i];
	}
	mean = sum / size;
	return mean;
}
