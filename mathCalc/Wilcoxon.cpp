#include "Headers.h"

Wilcoxon::Wilcoxon() :
m_data1(nullptr),
m_data2(nullptr)
{
}

bool Wilcoxon::calcDifference()
{
	if (m_data1->size() != m_data2->size())
	{
		std::cout << "Unproper data";
		return false;
	}

	for (size_t i = 0; i < m_data1->size(); i++)
	{
		double diff = (*m_data1)[i] - (*m_data2)[i];
		double absDiff = abs(diff);
		Results output(diff, absDiff);
		m_result.push_back(output);
	}
	return true;
}

bool Wilcoxon::createRanks()
{
	std::sort(m_result.begin(), m_result.end());
	int counter = 1;
	for (size_t i = 0; i < m_result.size(); ++i)
	{
		m_result[i].rank = counter;
		counter++;
	}

	double sum = 0;

	for (size_t i = 0; i < m_result.size(); ++i)
	{
		int begin, end, k;
		if (m_result[i].absDiff == m_result[i + 1].absDiff)
		{
			begin = end = k = i;
			while (m_result[k].absDiff == m_result[k + 1].absDiff)
			{
				k++;
				end++;
			}
			k = begin;
			int number = (end - begin)+1;
			for (k; k <= end; k++)
			{
				sum += m_result[k].rank;
			}
			double newRank;
			newRank = sum / number;

			for (begin; begin <= end; ++begin)
			{
				m_result[begin].rank = newRank;
			}
		}
	}

	for (int i = 0; i< m_result.size(); ++i)
		std::cout << m_result[i].rank << ' ' << m_result[i].absDiff << std::endl;


	return true;
}

bool Wilcoxon::performTest(const std::vector<double> &vec1, const std::vector<double> &vec2)
{
	m_data1 = &vec1;
	m_data2 = &vec2;

	if (!calcDifference())
	{
		return false;
	}

	if(!createRanks())
	{
		std::cout << "Unable to perform test";
	}
	
}