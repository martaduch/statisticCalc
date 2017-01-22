#include "Headers.h"

DataReader::DataReader(const char *filepath, std::vector<std::vector<double>> &data, char delimiter/*=NULL*/) :
	m_line(1),
	m_columns(0),
	m_data(data),
	m_delimiter(delimiter)
{
	std::ifstream myfile(filepath);

	if (myfile.is_open())
	{
		try
		{
			while (getline(myfile, m_text))
			{
				if (m_text.size() == 0) // line is empty
				{
					continue;
				}

				processLine();
				m_line++;
			}
		}
		catch (std::exception)
		{
			myfile.close();
			throw;
		}

		myfile.close();
	}
	else
	{
		throw std::exception("Unable to open file");
	}
}


void DataReader::processLine()
{
	if (m_delimiter == NULL)
	{
		m_delimiter = findDelimiter();
	}

	if (!checkLine())
	{
		malformedDataException();
	}

	const size_t delimitersNum = getCharCount(m_text, m_delimiter);

	if (m_columns == 0)
	{
		m_columns = delimitersNum + 1;
		for (size_t i = 0; i < m_columns; i++)
		{
			std::vector<double> v;
			m_data.push_back(v);
		}
	}
	else if (m_columns != delimitersNum + 1)
	{
		malformedDataException();
	}

	explode();
}


char DataReader::findDelimiter()
{
	for (size_t i = 0; i < m_text.size(); i++)
	{
		if (!isdigit(m_text[i]) && m_text[i] != '.' && m_text[i] != '-')
		{
			return m_text[i];
		}
	}

	throw std::exception("Failed to find data delimiter");
}


bool DataReader::checkLine()
{
	for (size_t i = 0; i < m_text.size(); i++)
	{
		if (!isdigit(m_text[i]) && m_text[i] != '.' && m_text[i] != '-' && m_text[i] != m_delimiter)
		{
			return false;
		}
	}

	return true;
}


void DataReader::explode()
{
	size_t start = 0;
	for (size_t i = 0; i < m_columns; i++)
	{
		size_t pos = m_text.find(m_delimiter, start);
		size_t end = std::string::npos;
		if (pos != std::string::npos)
		{
			end = pos - start;
		}

		std::string number = m_text.substr(start, end);
		m_data[i].push_back(stod(number));

		start = pos + 1;
	}
}


inline void DataReader::malformedDataException()
{
	std::stringstream error;
	error << "Malformed data on line " << m_line;
	throw std::exception(error.str().c_str());
}


inline size_t DataReader::getCharCount(const std::string &str, const char c)
{
	return std::count(str.begin(), str.end(), c);
}