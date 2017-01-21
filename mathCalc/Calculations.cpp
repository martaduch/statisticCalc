#include "Calculations.h"



Calculations::Calculations(vector<vector<double>> &data, ArgParser object):
	m_columns(object.getColumns()),
	m_test(object.getToDo())
{
	for (size_t i = 0; i < m_columns.length(); i++) //-1 because of range
	{
		if (m_columns[0] == 'a')
		{
			for (size_t i = 0; i < data.size(); i++)
				m_readyData.push_back(data[i]);
			break;
		}
		if (isdigit(m_columns[i])) {
			int number = m_columns[i]-'0';
			m_readyData.push_back(data[number-1]);
		}
			
	}
}

void Calculations::run()
{
	switch (m_test)
	{
	case 'w': {
		Wilcoxon w;
		w.performTest(m_readyData[0], m_readyData[1]);
		break;
	}

	case 'g':
		for (size_t i = 0; i < m_readyData.size(); i++)
		{
			Math m(m_readyData[i]);
			m.performTest();
		}
		break;

	case 'f':
		Friedman f(m_readyData);
		f.performTest();
		break;
	}
}