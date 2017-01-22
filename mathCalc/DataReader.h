#pragma once
#include "Headers.h"

class DataReader
{
private:
	size_t m_line;
	size_t m_columns;
	char m_delimiter;
	std::string m_text;
	std::vector<std::vector<double>> &m_data;

	void processLine();
	char findDelimiter();
	bool checkLine();
	void explode();
	inline void malformedDataException();
	inline size_t getCharCount(const std::string &str, const char c);

public:
	DataReader(const char *filepath, std::vector<std::vector<double>> &data, char delimiter = NULL);
	~DataReader() {};
};
