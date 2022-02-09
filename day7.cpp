#include "day7.h"


Day7::Day7(const char* path)
{
	const std::vector<std::string> lines = readFile(path);

	for (const std::string& line : lines)
	{
		const std::vector< std::string> temp = splitString(line, ",");
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

void runDay7()
{
	Day7 day7("res/day7.txt");
	std::cout << "La moyenne est de " << day7.getMean() << std::endl;
}