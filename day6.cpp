#include "day6.h"

void Day6::populateFishes()
{
	const std::vector<std::string> fileContent = readFile(m_filePath);
	const std::vector<std::string> strFishes = splitString(fileContent[0], ",");

	for (const std::string& f : strFishes)
	{
		switch (std::stoi(f))
		{
		case 0:
			m_fishesState[0]++;
			break;
		case 1:
			m_fishesState[1]++;
			break;
		case 2:
			m_fishesState[2]++;
			break;
		case 3:
			m_fishesState[3]++;
			break;
		case 4:
			m_fishesState[4]++;
			break;
		case 5:
			m_fishesState[5]++;
			break;
		case 6:
			m_fishesState[6]++;
			break;
		case 7:
			m_fishesState[7]++;
			break;
		case 8:
			m_fishesState[8]++;
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

	for (size_t i = 0; i < TIMER_STATES; i++)
	{
		//std::cout << m_fishesState[i] << std::endl;
		totalPopulation += m_fishesState[i];
	}

	return totalPopulation;
}



void Day6::doFishes(const int days)
{
	int dayCounter = 0;
	while (dayCounter < days)
	{
		size_t newFishes = 0;
		int64_t nextState[TIMER_STATES] = { 0 };	// track differences between old and newState

		for (size_t i = 0; i < TIMER_STATES; i++) // !! NE PAS MUTER L'ETAT EN COURS DANS CETTE BOUCLE !!!
		{
			switch (i)
			{
				// entrées
				// sorties
			case 0:
				nextState[6] += m_fishesState[0];
				newFishes += m_fishesState[0];
				nextState[i] -= m_fishesState[i];
				break;
			case 1:
				nextState[i - 1] += m_fishesState[i];
				nextState[i] -= m_fishesState[i];
				break;
			case 2:
				nextState[i - 1] += m_fishesState[i];
				nextState[i] -= m_fishesState[i];
				break;
			case 3:
				nextState[i - 1] += m_fishesState[i];
				nextState[i] -= m_fishesState[i];
				break;
			case 4:
				nextState[i - 1] += m_fishesState[i];
				nextState[i] -= m_fishesState[i];
				break;
			case 5:
				nextState[i - 1] += m_fishesState[i];
				nextState[i] -= m_fishesState[i];
				break;
			case 6:
				nextState[i - 1] += m_fishesState[i];
				nextState[i] -= m_fishesState[i];
				break;
			case 7:
				nextState[i - 1] += m_fishesState[i];
				nextState[i] -= m_fishesState[i];
				break;
			case 8:
				nextState[i - 1] += m_fishesState[i];
				nextState[i] += newFishes;

				nextState[i] -= m_fishesState[i];
				break;
			}
		}



		// compute currentState: oldState += newState
		for (size_t i = 0; i < TIMER_STATES; i++)
		{
			m_fishesState[i] += nextState[i];
		}

		dayCounter++;
	}

}

void runDay6()
{
	Day6 day6("res/day6.txt");
	std::cout << day6.computePopulationSize() << std::endl;

	day6.doFishes(256);
	std::cout << day6.computePopulationSize() << std::endl;
}