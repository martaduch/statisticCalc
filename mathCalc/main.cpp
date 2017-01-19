#include "Headers.h"

int main(int argc, char* argv[]){


	ArgParser param;
	param.assignData(argc, argv);

	vector<vector<double>> data;
	try
	{
		DataReader reader("input.txt", data);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			std::cout << data[i][j] <<std::endl;
		}
	}
	return 0;
}