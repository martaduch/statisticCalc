#pragma once

struct Results
{
	double diff;
	double absDiff;
	double rank;

	Results(double diff, double absDiff):
	diff(diff),
	absDiff(absDiff),
	rank(0)
	{
	}

	bool operator < (const Results& str) const
	{
		return (absDiff < str.absDiff);
	}
};
 
class Wilcoxon
{
	std::vector<Results> m_result;
	bool Wilcoxon::isEqual(double a, double b);
	bool calcDifference();
	bool createRanks();
	const std::vector<double> *m_data1;
	const std::vector<double> *m_data2;
public:
	Wilcoxon();
	bool performTest(const std::vector<double> &vec1, const std::vector<double> &vec2);
	//void performTest();
};