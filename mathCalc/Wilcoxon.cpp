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
		Results output(diff);
		m_result.push_back(output);
	}
}

/*bool Wilcoxon::createRanks()
{
	int counter = 1;
	for (size_t i = 0; i < m_datas->size(); i++)
	{
		if (m_datas[i].difference != m_datas[i + 1].difference)
		{
			output[i].rank = counter;
		}
		else
		{

		}
		k++;
	}
}*/

void Wilcoxon::performTest(const std::vector<double> &vec1, const std::vector<double> &vec2)
{
	m_data1 = &vec1;
	m_data2 = &vec2;

	calcDifference();

	//if(!createRanks())
	//{
	//	std::cout << "Unable to perform test";
	//}
	//
}