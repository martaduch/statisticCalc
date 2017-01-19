#include "Headers.h"

void ArgParser::help()
{
	std::cout << "\t *** HELP ***" << std::endl;
	std::cout << "How to set arguments properly: "<< std::endl;
	std::cout << "-i path to input file" << std::endl;
	std::cout << " -c columns to be used separeted with colons" << std::endl; 
	std::cout << "-t test to be performed:" << std::endl;
	std::cout << "\t s - standard tests, w - Wilcoxon test, f - friedman test" << std::endl;
	std::cout << "Example: -t input.txt -c 5,6 -t w,f";
}

bool ArgParser::assignData(int argc, char *argv[])
{
	if (argc < 7)
	{
		help();
		return false;
	}

	for (size_t i = 1; i < argc - 1; i++)
	{
		switch (argv[i][1])
		{
		case 'i':
			params.filePath = argv[i + 1];
			break;
		case 'c':
			params.columns = argv[i + 1];
			break;
		case 't':
			params.toDo = argv[i + 1][0];
			break;
			//default ?
		}
	}

	return true;
}

ArgParser::parameters ArgParser::getParams()
{
	return params;
}
