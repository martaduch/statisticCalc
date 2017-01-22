#include "Headers.h"

int main(int argc, char* argv[]){

	ArgParser param;
	if (!param.assignData(argc, argv))
		return 1;

	vector<vector<double>> data;
	try
	{
		DataReader reader(param.getPath().c_str(), data);
		Tests calc(data, param);
		calc.run();
	}
	catch (exception &e)
	{
		cout << e.what() << endl;
		return 1;
	}

	return 0;
}