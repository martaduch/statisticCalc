#pragma once
#include "Headers.h"

class Tests
{
	std::stringstream m_columns;
	char m_test;
	std::vector<std::vector<double>> m_readyData;
public:
	Tests(std::vector<std::vector<double>> &data, ArgParser object);
	~Tests() {};
	void run();
};

