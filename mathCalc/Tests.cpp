#include "Headers.h"

Tests::Tests(vector<vector<double>> &data, ArgParser object):
	m_columns(object.getColumns()),
	m_test(object.getToDo())
{
		std::vector<int> vect;
		int i;
		while (m_columns >> i)
		{
			vect.push_back(i);
			if (m_columns.peek() == ',')
				m_columns.ignore();
		}
		for (size_t i = 0; i < vect.size(); i++) 
		{
			if (vect[i] > data.size())
				throw exception("Column out of range");
			m_readyData.push_back(data[vect[i] - 1]);
		}
}

void Tests::run()
{
	switch (m_test)
	{
	case 'w': {
		Wilcoxon w;
		w.performTest(m_readyData[0], m_readyData[1]);
		break;
	}

	case 'g': {
		for (size_t i = 0; i < m_readyData.size(); i++)
		{
			Math m(m_readyData[i]);
			m.performTest();
		}
		break;
	}

	case 'f':
	{
		Friedman f(m_readyData);
		f.performTest();
		break;
	}
	
	default:
		std::cout << "unknown test" << std::endl;
		break;
	}

}