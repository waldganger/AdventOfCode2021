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
	for (size_t i = 0; i < m_positions.size(); i++)
	{
		for (size_t j = i; j < m_positions.size(); j++)
		{
			if (m_positions[j] == m_positions[i])
			{
				bool valueExists = false;
				for (Occurence& o : m_SortedOccurences)
				{
					if (m_positions[i] == o.value)
					{
						o.counter++;
						valueExists = true;
						break;
					}
				}

				if(valueExists == false) 
					m_SortedOccurences.push_back({ m_positions[i], 1 });
			}
		}
	}

	std::sort(m_SortedOccurences.begin(), m_SortedOccurences.end(), [](Occurence a, Occurence b) {
		return a.counter > b.counter;
		});
}





void Day7::printAlignes() const
{
	for (const Occurence& o : m_SortedOccurences)
	{
		std::cout << o.value << " apparait " << o.counter << " fois." << std::endl;
	}
}

// 1. Prendre conso = uint32::max
// 2. Prendre chaque valeur commme point de référence
// 3. Pour chaque valeur, calculer la distance avec le point de référence, et multiplier par nombre occurences => additionner le tout
// 2. Trouver le nombre commun le plus proche de la moyenne
uint32_t Day7::computeBestSpot() const
{
	uint32_t minFuelCons = 1 << 32 - 1;
	return minFuelCons;
}



void runDay7()
{
	Day7 day7("res/day7.txt");
	std::cout << "La moyenne est de " << day7.getMean() << std::endl;
	day7.detectAlignes();
	day7.printAlignes();
	std::cout << day7.computeBestSpot() << std::endl;
}