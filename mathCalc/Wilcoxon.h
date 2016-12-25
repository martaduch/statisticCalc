#pragma once

struct Results
{
	double difference;
	double rank;

	Results(double difference):
	difference(difference),
	rank(0)
	{
	}
};
 
class Wilcoxon
{
	std::vector<Results> m_result;
	bool calcDifference();
	//bool createRanks();
	const std::vector<double> *m_data1;
	const std::vector<double> *m_data2;
public:
	Wilcoxon();
	void performTest(const std::vector<double> &vec1, const std::vector<double> &vec2);
	//void performTest();
};