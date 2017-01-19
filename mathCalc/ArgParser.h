#pragma once
#include <string>

class ArgParser
{
	struct parameters
	{
		std::string filePath;
		std::string columns;
		char toDo;
	} params;
public:
	ArgParser() {};
	~ArgParser() {};
	void help();
	bool assignData(int argc, char *argv[]);
	void toDo();
	parameters getParams();
};

