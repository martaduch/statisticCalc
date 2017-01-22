#include "Headers.h"

int main(int argc, char* argv[]){

	ArgParser param;
	if (!param.assignData(argc, argv))
		return 1;

	std::vector<std::vector<double>> data;
	try
	{
		DataReader reader(param.getPath().c_str(), data, param.getDelimiter());
		Tests test(data, param);
		test.run();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	return 0;
}