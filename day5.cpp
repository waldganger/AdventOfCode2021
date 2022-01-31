#include "day5.h"
#include <limits>
#include <cmath>


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

void Day5::acquireEdgeCoordinates()
{
	m_edges = { std::numeric_limits<int>::max(), std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), std::numeric_limits<int>::min() };

	for (auto c : m_vents)
	{
		if (c.x1 < m_edges.minX) m_edges.minX = c.x1;
		if (c.x2 < m_edges.minX) m_edges.minX = c.x2;
		if (c.x1 > m_edges.maxX) m_edges.maxX = c.x1;
		if (c.x2 > m_edges.maxX) m_edges.maxX = c.x2;

		if (c.y1 < m_edges.minY) m_edges.minY = c.y1;
		if (c.y2 < m_edges.minY) m_edges.minY = c.y2;
		if (c.y1 > m_edges.maxY) m_edges.maxY = c.y1;
		if (c.y2 > m_edges.maxY) m_edges.maxY = c.y2;
	}
}

// TODO: à tester.
bool isDiagonal(const Line& line)
{
	int dx = std::abs(line.x1 - line.x2);
	int dy = std::abs(line.y1 - line.y2);
	if (dx == 0 || dy == 0) return false;		// la ligne est verticale ou horizontale
	if (dx == dy) return true;
	return false;
}


void Day5::doDiagram()
{
	const size_t columnLength = (size_t)m_edges.maxX + 1;
	const size_t lineLength = (size_t)m_edges.maxY + 1;
	char overlap = 49;

	std::vector<char> diagramLine(columnLength, '.');

	for (size_t i = 0; i < lineLength; i++)
	{
		m_diagram.push_back(diagramLine);
	}



	for (const Line& line : m_vents)
	{
		if (line.x1 == line.x2 || line.y1 == line.y2)							// For now, only consider horizontal and vertical lines
		{
			if (line.x1 == line.x2)												// vertical line
			{

				const size_t begin = line.y1 > line.y2 ? line.y2 : line.y1;
				const size_t end = line.y1 > line.y2 ? line.y1 : line.y2;

				const size_t offset = line.y1 > line.y2 ? line.y1 - line.y2 : line.y2 - line.y1;

				for (size_t i = begin; i <= end; i++)
				{
					if (m_diagram[i][line.x1] == '.')
					{
						m_diagram[i][line.x1] = 49;
					}
					else
					{
						m_diagram[i][line.x1]++;

					}
				}
			}
			else																// horizontal line
			{
				const size_t begin = line.x1 > line.x2 ? line.x2 : line.x1;
				const size_t end = line.x1 > line.x2 ? line.x1 : line.x2;

				const size_t offset = line.x1 > line.x2 ? line.x1 - line.x2 : line.x2 - line.x1;

				for (size_t i = begin; i <= end; i++)
				{
					if (m_diagram[line.y1][i] == '.')
					{
						m_diagram[line.y1][i] = 49;
					}
					else
					{
						m_diagram[line.y1][i]++;

					}
				}
			}
		}

	}
}

void Day5::displayDiagram() const
{
	const size_t columnLength = (size_t)m_edges.maxX - (size_t)m_edges.minX;
	const size_t lineLength = (size_t)m_edges.maxY - (size_t)m_edges.minY;

	for (size_t c = 0; c < columnLength; c++)
	{
		for (size_t l = 0; l < lineLength; l++)
		{
			std::cout << m_diagram[l][c];
		}
		std::cout << std::endl;
		std::cout << std::endl;
	}
}

void Day5::overlap()
{
	for (const auto line : m_diagram)
	{
		for (const auto ch : line)
		{
			if (ch >= 50) m_overlap++;
			if (ch < 46) throw std::exception("pas marché");
		}
	}
}




void runDay5()
{
	Day5 day5("res/day5.txt");
	//day5.displayVentsCoordinates();
	//day5.displayDiagram();
	day5.overlap();
}