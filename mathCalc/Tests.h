#pragma once
#include "Headers.h"

class Tests
{
	std::stringstream m_columns;
	char m_test;
	std::vector<vector<double>> m_readyData;
public:
	Tests(vector<vector<double>> &data, ArgParser object);
	~Tests() {};
	void run();
};

