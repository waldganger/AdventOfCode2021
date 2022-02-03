#include "day6.h"

void Day6::populateFishes()
{
	const std::vector<std::string> fileContent = readFile(m_filePath);
	const std::vector<std::string> strFishes = splitString(fileContent[0], ",");
	std::vector<int> initialState;

	for (const std::string& f : strFishes)
	{
		initialState.push_back(std::stoi(f));
	}

	m_fishesStates.push_back(initialState);
}

void Day6::print() const
{
	int dayCounter = 0;

	for (const std::vector<int>& dayPop : m_fishesStates)
	{
		if (dayCounter == 0)
		{
			std::cout << "Initial state: ";
		}
		else
		{
			std::cout << "after " << dayCounter << (dayCounter > 1 ? " days " : " day : ") << dayCounter;
		}
		for (size_t i = 0; i < dayPop.size(); i++)
		{
			std::cout << dayPop[i] << (i == dayPop.size() - 1 ? "" : ",");
		}
		dayCounter++;
		std::cout << std::endl;
	}

}

int Day6::doFishes(const int days)
{
	int dayCounter = 0;
	while (dayCounter < days)
	{
		std::vector<int> newState;
		int newFishes = 0;
		for (int fish : m_fishesStates[dayCounter])
		{
			switch (fish)
			{
			case 0:
				newState.push_back(6);
				newFishes++;
				break;
			default:
				newState.push_back(fish - 1);
				break;
			}
		}

		for (size_t i = 0; i < newFishes; i++)
		{
			newState.push_back(8);
		}

		m_fishesStates.push_back(newState);
		dayCounter++;
	}

	return m_fishesStates.back().size();
}

void runDay6()
{
	Day6 day6("res/day6.txt");
	const int result = day6.doFishes(80);
	std::cout << result << std::endl;
}