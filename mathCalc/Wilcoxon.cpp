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

	size_t rank = 1;
	for (size_t i = 0; i < m_result.size(); i++)
	{
		if (m_result[i].diff)
		{
			m_result[i].rank = rank;
			rank++;
			m_nonZero++;
		}
	}

	if (m_nonZero < 6 || m_nonZero > 50)
	{
		std::cout << "Unable to perform test. Improper data. Number of trials should be beetwen 6-50" << std::endl;
		return false;
	}

	for (size_t i = 0; i < m_result.size()-1; i++) //-1 to prevent being out of range
	{
		size_t begin, end;

		if (isEqual(m_result[i].absDiff, m_result[i + 1].absDiff))
		{
			begin = i;
			double sum = m_result[i].rank;

			for (end = i+1; isEqual(m_result[end].absDiff, m_result[end + 1].absDiff); end++)
			{
				sum += m_result[end].rank;
			}
			sum += m_result[end].rank; 

			size_t numberOfElements = (end - begin) + 1;
			double newRank = sum / numberOfElements;

			for (begin; begin <= end; begin++)
			{
				m_result[begin].rank = newRank;
			}
		}
	}
	return true;
}

bool Wilcoxon::isEqual(double a, double b)
{
	const double epsilon = 0.0000000000001;

	return (b - epsilon <= a && a <= b + epsilon);
}

void Wilcoxon::signRanks()
{
	for (size_t i = 0; i < m_result.size(); i++)
	{
		if (m_result[i].diff < 0)
			m_result[i].rank = -m_result[i].rank;
	}
}

bool Wilcoxon::tStaticticW()
{
	//a = 0.05
	int wCritical[] = { 0, 2, 3, 5, 8, 10, 13, 17, 21, 25, 29, 34, 40, 46, 52, 58, 65, 73, 81, 89, 98, 107, 116, 126, 137, 147,
						159, 170, 182, 195, 208, 221, 235, 249, 264, 279, 294, 310, 327, 343, 361, 378, 396, 415, 434 };
	double wPositive = 0, wNegative = 0;

	for (size_t i = 0; i < m_result.size(); i++)
	{
		if (m_result[i].rank > 0)
			wPositive += m_result[i].rank;
		else
			wNegative += m_result[i].rank;
	}

	wPositive = abs(wPositive);
	wNegative = abs(wNegative);
	
	std::cout << "Sum of positive difference rank is " << wPositive << std::endl;
	std::cout << "Sum of negative difference rank is " << wNegative << std::endl;

	int wValue; 
	if (wPositive < wNegative)
		wValue = (int)round(wPositive);
	else
		wValue = (int)round(wNegative);

	std::cout << "W statistic is " << wValue << std::endl;

	if (wValue <= wCritical[m_nonZero - 6])
		return true;
	else
		return false;
}

bool Wilcoxon::performTest(std::vector<double> &vec1, std::vector<double> &vec2)
{
	m_data1 = &vec1;
	m_data2 = &vec2;

	if (!calcDifference())
	{
		std::cout << "Unable to perform test";
		return false;
	}

	if(!createRanks())
		return false;
	
	std::cout << "Effective sample size is " << m_nonZero << std::endl;

	signRanks();
	if (tStaticticW())
		std::cout << "Reject Null Hypothesis as calculated W <= W critical";
	else
		std::cout << "Fail to reject H0 as W > W critical";

	return true;
}