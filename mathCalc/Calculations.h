#pragma once
#include "Headers.h"

class Calculations
{
	std::string m_columns;
	char m_test;
	std::vector<vector<double>> m_readyData;
public:
	Calculations(vector<vector<double>> &data, ArgParser object);
	~Calculations() {};
	void run();
};

