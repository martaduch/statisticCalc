#pragma once
#include <string>

class ArgParser
{
	std::string m_filePath;
	std::string m_columns;
	char m_delimiter = NULL;
	char m_toDo;
public:
	ArgParser() {};
	~ArgParser() {};
	void help();
	bool assignData(int argc, char *argv[]);
	std::string getPath();
	std::string getColumns();
	char getDelimiter();
	char getToDo();
};

