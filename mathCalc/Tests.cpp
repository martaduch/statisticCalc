#include "Headers.h"

Tests::Tests(std::vector<std::vector<double>> &data, ArgParser argParser):
	m_columns(argParser.getColumns()),
	m_test(argParser.getToDo())
{
		std::vector<int> vect;
		int i;
		while (m_columns >> i)
		{
			if (i == 0)
			{
				for (size_t j = 0; j < data.size(); j++)
				{
					m_readyData.push_back(data[i]);
				}
				break;
			}
			else
			{
				vect.push_back(i);
				if (m_columns.peek() == ',')
					m_columns.ignore();
			}
			
		}
		for (size_t i = 0; i < vect.size(); i++) 
		{
			if (vect[i] > data.size())
				throw std::exception("Column out of range");
			m_readyData.push_back(data[vect[i] - 1]);
		}
}

void Tests::run()
{
	switch (m_test)
	{
	case 'w': {
		Wilcoxon w;
		if (m_readyData.size() < 2)
			std::cout << "Improper data; at least 2 columns needed" << std::endl;
		else
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