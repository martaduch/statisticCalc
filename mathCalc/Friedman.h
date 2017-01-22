#pragma once
class Friedman
{
	std::vector<std::vector<double>> dataVector;
	std::vector<double> m_sumRanks;
	bool signRanks();
	void sumRanks();
	double chiValue();
	bool compare();
	size_t m_degFreedom;
public:
	bool performTest();
	Friedman(std::vector<std::vector<double>> &vec);
	~Friedman() {};
};

