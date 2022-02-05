#include "day6.h"

void Day6::populateFishes()
{
	const std::vector<std::string> fileContent = readFile(m_filePath);
	const std::vector<std::string> strFishes = splitString(fileContent[0], ",");

	for (const std::string& f : strFishes)
	{
		m_fishesState.push_back(std::stoi(f));
	}
}


size_t Day6::doFishes(const int days)
{
	int dayCounter = 0;
	size_t previousDay = 1;
	double rapport = 0;
	while (dayCounter < days)
	{
		size_t newFishes = 0;
		for (uint8_t& fish : m_fishesState)
		{
			switch (fish)
			{
			case 0:
				fish = 6;
				newFishes++;
				break;
			default:
				fish--;
				break;
			}
		}

		for (size_t i = 0; i < newFishes; i++)
		{
			m_fishesState.push_back(8);
		}

		dayCounter++;
		std::cout << "day " << dayCounter << " population " << m_fishesState.size() << std::endl;



	}

	return m_fishesState.size();
}

void runDay6()
{
	Day6 day6("res/day6.txt");
	const size_t result = day6.doFishes(200);
	std::cout << result << std::endl;
}