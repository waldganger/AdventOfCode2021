#include "day6.h"

void Day6::populateFishes()
{
	const std::vector<std::string> fileContent = readFile(m_filePath);
	const std::vector<std::string> strFishes = splitString(fileContent[0], ",");

	for (const std::string& f : strFishes)
	{
		m_fishes.push_back(std::stoi(f));
	}
}

void Day6::print()
{
	for (const int& fish : m_fishes)
	{
		std::cout << fish << std::endl;
	}
}

void runDay6()
{
	Day6 day6("res/day6.txt");
	day6.print();
}