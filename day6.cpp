#include "day6.h"

void Day6::initDataContainer()
{
	for (size_t i = 0; i < TIMER_STATES; i++)
	{
		m_fishesState[i] = { (uint8_t)i, 0 };
	}
}

void Day6::populateFishes()
{
	const std::vector<std::string> fileContent = readFile(m_filePath);
	const std::vector<std::string> strFishes = splitString(fileContent[0], ",");

	for (const std::string& f : strFishes)
	{
		switch (std::stoi(f))
		{
		case 0:
			m_fishesState[0].count++;
			break;
		case 1:
			m_fishesState[1].count++;
			break;
		case 2:
			m_fishesState[2].count++;
			break;
		case 3:
			m_fishesState[3].count++;
			break;
		case 4:
			m_fishesState[4].count++;
			break;
		case 5:
			m_fishesState[5].count++;
			break;
		case 6:
			m_fishesState[6].count++;
			break;
		case 7:
			m_fishesState[7].count++;
			break;
		case 8:
			m_fishesState[8].count++;
			break;
		default:
			throw "logic error : bad stoi conversion.";
			break;
		}
	}
}

uint64_t Day6::computePopulationSize() const
{
	uint64_t totalPopulation = 0;

	for (const Timer& popSlice : m_fishesState)
	{
		std::cout << popSlice.count << std::endl;
		totalPopulation += popSlice.count;
	}

	return totalPopulation;
}



void Day6::doFishes(const int days)
{
	int dayCounter = 0;
	while (dayCounter < days)
	{
		size_t newFishes = 0;
		for (size_t i = 0; i < TIMER_STATES; i++)
		{
			switch (i)
			{
			case 0:
				m_fishesState[6].count += m_fishesState[0].count;
				newFishes += m_fishesState[0].count;
				m_fishesState[0].count = 0;
				break;
			case 1:

				m_fishesState[0].count += m_fishesState[1].count;
				m_fishesState[1].count = 0;
				break;
			case 2:
				m_fishesState[1].count += m_fishesState[2].count;
				m_fishesState[2].count = 0;
				break;
			case 3:
				m_fishesState[2].count += m_fishesState[3].count;
				m_fishesState[3].count = 0;
				break;
			case 4:
				m_fishesState[3].count += m_fishesState[4].count;
				m_fishesState[4].count = 0;
				break;
			case 5:
				m_fishesState[4].count += m_fishesState[5].count;
				m_fishesState[5].count = 0;
				break;
			case 6:
				m_fishesState[5].count += m_fishesState[6].count;
				m_fishesState[6].count = 0;
				break;
			case 7:
				m_fishesState[6].count += m_fishesState[7].count;
				m_fishesState[7].count = 0;
				break;
			case 8:
				m_fishesState[7].count += m_fishesState[8].count;
				m_fishesState[8].count = newFishes;
				break;
			default:
				throw "logic error : bad timer input";
				break;
			}


			/*switch (fish)
			{
			case 0:
				fish = 6;
				newFishes++;
				break;
			default:
				fish--;
				break;
			}*/
		}

		//m_fishesState[8].count += newFishes;

		dayCounter++;
		//std::cout << "day " << dayCounter << " population " << computePopulationSize() << std::endl;
	}

}

void runDay6()
{
	Day6 day6("res/day6.txt");
	day6.doFishes(80);
	std::cout << day6.computePopulationSize() << std::endl;
}