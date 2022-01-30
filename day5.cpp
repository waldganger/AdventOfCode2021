#include "day5.h"


void Day5::readFile()
{
	std::ifstream file;
	file.open(m_filePath, std::ios::in);
	if (file.is_open())
	{
		std::string buffer;
		while (std::getline(file, buffer))
		{
			m_fileContents.push_back(buffer);
		}
	}
	file.close();
}

void Day5::populateVents()
{
	for (auto l : m_fileContents)
	{
		std::vector<std::string> pairStrings = splitString(l, " -> ");
		std::vector<std::vector<std::string>> quadStrings;
		std::vector<int> coordinates;

		for (auto str : pairStrings)
		{
			quadStrings.push_back(splitString(str, ","));
		}
		for (auto pair : quadStrings)
		{
			for (auto number : pair)
			{
				coordinates.push_back(std::stoi(number));
			}
		}
		m_vents.push_back({ coordinates[0], coordinates[1], coordinates[2], coordinates[3] });
	}
}

void Day5::displayFileContents() const
{
	for (const std::string& line : m_fileContents)
	{
		std::cout << line << std::endl;
	}
}
void Day5::displayVentsCoordinates() const
{
	for (const Line& l : m_vents)
	{
		std::cout << l.x1 << "," << l.y1 << " -> " << l.x2 << "," << l.y2 << std::endl;
	}
}


void runDay5()
{
	Day5 day5("res/day5.txt");
	day5.displayVentsCoordinates();
}