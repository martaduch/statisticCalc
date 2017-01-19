#pragma once
#include <string>

class FileOperations
{
	std::string filePath;
	bool wilcoxon;
	bool friedman;
	bool standardOp;
	std::string columns;
	std::string toDo;
public:
	FileOperations();
	~FileOperations();
	void help();
	bool assignData(int argc, char *argv[]);
};

