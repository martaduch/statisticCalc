
#include "Headers.h"

int main(int argc, char* argv[]){

	for (size_t i = 2; i < argc; i++) {
		std::cout <<argv[i] << std::endl;
	}

	FileOperations param;
	param.assignData(argc, argv);

	
	return 0;
}