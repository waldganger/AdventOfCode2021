#include "day7.h"


Day7::Day7(const char* path)
{ 
	m_filePath = path;
	
	if (m_filePath == NULL) return;

	const std::vector<std::string> lines = readFile(path);

	for (const std::string& line : lines)
	{
		const std::vector<std::string> temp = splitString(line, ",");
		for (const std::string strNum : temp)
		{
			m_positions.push_back(std::stoi(strNum));
		}
	}

}

uint32_t Day7::getMean() const
{
	uint32_t sum = 0;
	for (const uint32_t& p : m_positions)
	{
		sum += p;
	}

	return sum / m_positions.size();
}

void Day7::detectAlignes() 
{
	uint32_t max;

	for (size_t i = 0; i < m_positions.size(); i++)
	{
		int counter = 0;
		for (size_t j = i; j < m_positions.size(); j++)
		{
			if (m_positions[j] == m_positions[i])
			{
				counter++;
			}
		}
		m_occurences.push_back({ m_positions[i], counter});
	}
}

void Day7::printAlignes() const
{
	for (const Occurence& o : m_occurences)
	{
		std::cout << o.number << " apparait " << o.counter << " fois." << std::endl;
	}
}



void runDay7()
{
	Day7 day7("res/day7.txt");
	std::cout << "La moyenne est de " << day7.getMean() << std::endl;
	day7.detectAlignes();
	day7.printAlignes();
}