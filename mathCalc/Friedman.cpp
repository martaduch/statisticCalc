#include "Headers.h"

Friedman::Friedman(std::vector<std::vector<double>> &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
	{
		dataVector.push_back(vec[i]);
	}
	m_dF = dataVector.size() - 1;
}


Friedman::~Friedman()
{
}

bool Friedman::signRanks()
{
	if (m_dF > 50)
		return false;

	for (size_t i = 0; i < dataVector.size(); i++)
	{
		vector<double> &column = dataVector[i];
		vector<size_t> usedIndexes;

		double rank = 1;
		while (true)
		{
			vector<size_t> indexes;
			double temp = 9999999999;

			for (size_t i = 0; i < column.size(); i++)
			{
				if (std::find(usedIndexes.begin(), usedIndexes.end(), i) == usedIndexes.end() && column[i] < temp)
				{
					temp = column[i];
					indexes.clear();
					indexes.push_back(i);
				}
				else if (column[i] == temp)
				{
					indexes.push_back(i);
				}
			}

			if (indexes.size() == 0)
			{
				break; // gtfo
			}

			usedIndexes.insert(usedIndexes.end(), indexes.begin(), indexes.end());

			double rankToAssign = ((rank + rank + indexes.size() - 1) / 2);
			rank += indexes.size();

			for (size_t i = 0; i < indexes.size(); i++)
			{
				column[indexes[i]] = rankToAssign;
			}
		}

		// print output
		for (size_t j = 0; j < column.size(); j++)
		{
			printf("%.02lf ", column[j]);
		}
		printf("\n");
	}
	return true;
}


void Friedman::sumRanks()
{
	for (size_t i = 0; i < dataVector.size(); i++)
	{
		double sum = 0;
		for (size_t j = 0; j < dataVector[0].size(); j++)
		{
			sum += dataVector[i][j];
		}
		m_sumRanks.push_back(sum);
	}
}


double Friedman::chiValue()
{
	int R = 0;
	for (size_t i = 0; i < m_sumRanks.size(); i++)
		R += m_sumRanks[i];
	size_t n = dataVector[0].size();
	size_t k = dataVector.size();

	return 12/(n*k *(k+1))*R - 3*n*(k+1) ;
}


bool Friedman::compare()
{
	//a=0.05
	double chiTable[] = { 3.84, 5.99, 7.81, 9.49, 11.07, 12.59, 14.07, 15.51, 16.92, 18.31, 19.68, 21.03, 22.36,
						23.69, 25, 26.2, 27.59, 28.87, 30.14, 31.41, 32.67, 33.92, 35.17, 36.42, 37.65, 38.89,
						40.11, 41.34, 42.56, 43.77, 44.99, 46.19, 47.4, 48.6, 49.8, 51, 52.19, 53.38, 54.57, 55.76,
						56.94, 58.12, 59.3, 60.48, 61.66, 62.83, 64, 65.17, 66.34};
	double Rcritical = chiTable[m_dF];
	if (chiValue() < Rcritical)
		return true;
	else
		return false;
}


bool Friedman::performTest()
{
	if (!signRanks()) {
		std::cout << "data format too big, unable to perform test" << std::endl;
		return false;
	}
	sumRanks();
	if (compare())
		std::cout << "Fail to reject Null Hypothesis as calculated Chi-Square <= Chi-Square critical";
	else
		std::cout << "Reject H0 as Chi-Square > Chi-square critical";
}