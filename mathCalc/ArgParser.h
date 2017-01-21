#pragma once
#include <string>

class ArgParser
{
	std::string m_filePath;
	std::string m_columns;
	char m_toDo;
public:
	ArgParser() {};
	~ArgParser() {};
	void help();
	bool assignData(int argc, char *argv[]);
	void toDo();
	std::string getPath();
	std::string getColumns();
	char getToDo();
};

