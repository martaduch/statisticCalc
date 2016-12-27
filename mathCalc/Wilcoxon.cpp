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
	for (size_t i = 0; i< m_result.size(); ++i)
		std::cout << m_result[i].rank << '\t' << m_result[i].absDiff << std::endl;
	std::cout << std::endl;

	for (size_t i = 0; i < m_result.size(); i++)
	{
		m_result[i].rank = i+1;
	}


	for (size_t i = 0; i < m_result.size()-1; i++) //-1 ¿eby nie wysz³o poza zakres
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

	for (size_t i = 0; i< m_result.size(); ++i)
		std::cout << m_result[i].rank << '\t' << m_result[i].absDiff << std::endl;


	return true;
}

bool Wilcoxon::isEqual(double a, double b)
{
	const double epsilon = 0.0000000000001;

	return (b - epsilon <= a && a <= b + epsilon);
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
	
	return true;
}