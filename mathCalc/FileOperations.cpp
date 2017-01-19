#include "Headers.h"



FileOperations::FileOperations()
{

}


FileOperations::~FileOperations()
{
}

void FileOperations::help() {
	std::cout << "\t *** HELP ***" << std::endl;
	std::cout << "How to set arguments properly: "<< std::endl;
	std::cout << "-i path to input file" << std::endl;
	std::cout << " -c columns to be used separeted with colons" << std::endl; 
	std::cout << "-t tests to be performed:" << std::endl;
	std::cout << "\t s - standard tests, w - Wilcoxon test, f - friedman test" << std::endl;
	std::cout << "Exammple: -t input.txt -c 5,6 -t w,f";
	Sleep(2000);
}

bool FileOperations::assignData(int argc, char *argv[]) {
	if (argc < 7)
	{
		help();
		return false;
	}

	/*for (size_t i = 2; i < argc; i++) {
		switch ((*argv)[i][1])
		{
		case 'i':
			filePath = (*argv)[i + 1];
			break;

		case '-c':
			columns = (*argv)[i + 1];
			break;
		case '-t':
			toDo = (*argv)[i + 1];
			break;
		}

	}*/
	for (size_t i = 2; i < argc; i++) {
		std::cout << (*argv)[i]<<std::endl;
	}

	return true;
}