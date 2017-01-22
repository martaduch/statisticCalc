#pragma once

#include <vector>

using namespace std;

class DataReader
{
private:
	size_t m_line;
	size_t m_columns;
	char m_delimiter;
	string m_text;
	vector<vector<double>> &m_data;

	void processLine();
	char findDelimiter();
	bool checkLine();
	void explode();
	inline void malformedDataException();
	inline size_t getCharCount(const string &str, const char c);

public:
	DataReader(const char *filepath, vector<vector<double>> &data, char delimiter = NULL);
	~DataReader() {};
};
