#include "Headers.h"

int main(int argc, char* argv[]){


	ArgParser param;
	if (!param.assignData(argc, argv))
		return 0;

	vector<vector<double>> data;
	try
	{
		DataReader reader(param.getPath().c_str(), data);
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
	}

	Calculations calc(data, param);
	calc.run();

	return 0;
}