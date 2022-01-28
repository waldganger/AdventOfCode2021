#include "day3.h"
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <fstream>


std::vector<std::string> parseBinFile(const char* path)
{
	std::fstream file;
	std::vector<std::string> v;
	file.open(path, std::ios::in);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			v.push_back(line);
		}
	}
	return v;
}

// From each column of the report, writes dominant bit in a string passed as argument
// Returns a string mapped to the report columns. The string flags with a '=' if the number of 0 equals the numbers of 1
std::string findDominantBits(const std::vector<std::string>& report, std::string& bitString)
{
	const size_t lineLenght = report[1].length();
	std::string eqChecker = "";

	for (size_t l = 0; l < lineLenght; l++)
	{
		int zeroCount = 0;
		int oneCount = 0;
		for (size_t c = 0; c < report.size(); c++)
		{
			switch (report[c][l])
			{
			case '0':
				zeroCount++;
				break;

			case '1':
				oneCount++;
				break;

			default:
				break;
			}
		}
		zeroCount == oneCount ? eqChecker.push_back('=') : eqChecker.push_back(' ');
		bitString.push_back(zeroCount > oneCount ? '0' : '1');
	}
	return eqChecker;
}

// returns -1 if same number of bits
int findDominantBitInColforRemainingLines(const std::vector<std::string>& report, const size_t col, std::vector<bool>& remainingLines)
{
	int zeroCount = 0;
	int oneCount = 0;

	for (size_t l = 0; l < report.size(); l++)
	{
		if (remainingLines[l] == true)
		{
			switch (report[l][col])
			{
			case '0':
				zeroCount++;
				break;

			case '1':
				oneCount++;
				break;

			default:
				break;
			}
		}
	}

	if (zeroCount == oneCount) return -1;
	return zeroCount > oneCount ? 0 : 1;
}


int getRating(const std::vector<std::string>& report, const std::string& eqChecker, Ratings method)
{
	const size_t reportLineLength = report[0].length();
	std::vector<std::string> matchingNumbers;
	std::vector<bool> linesToKeep(report.size());
	int goodLinesRemaining = 0;
	for (auto l : linesToKeep)
	{
		l = true;
		goodLinesRemaining++;
	}

	for (size_t c = 0; c < reportLineLength; c++)
	{
		const int commonBit = findDominantBitInColforRemainingLines(report, c, linesToKeep);

		if (commonBit == -1)
		{
			for (size_t l = 0; l < report.size(); l++)
			{
				if (linesToKeep[l] == false) continue;
				std::string temp(1, report[l][c]);
				const int currentBit = std::stoi(temp);
				int bitCriteria = (method == Ratings::oxygen_generator ? 1 : 0);

				if (currentBit != bitCriteria)
				{
					linesToKeep[l] = false;

					if (goodLinesRemaining == 1)
					{
						return std::stoi(report[l], nullptr, 2);
					}
					goodLinesRemaining--;
				}
			}
		}
		else
		{
			for (size_t l = 0; l < report.size(); l++)
			{
				if (linesToKeep[l] == false) continue;

				std::string temp(1, report[l][c]);
				const int currentBit = std::stoi(temp);

				// depending on rating method, keep the most OR least common bit in the current bit position, and keep only lines with that bit in that position.
				int bitCriteria = (method == Ratings::oxygen_generator ? commonBit : (commonBit == 1 ? 0 : 1));

				if (currentBit != bitCriteria)
				{
					linesToKeep[l] = false;
					if (goodLinesRemaining == 1)
					{
						return std::stoi(report[l], nullptr, 2);
					}
					goodLinesRemaining--;
				}
			}
		}

	}

	int lastLineStandingIndex = 0;

	for (int i = 0; i < linesToKeep.size(); i++)
	{
		if (linesToKeep[i])
		{
			lastLineStandingIndex = i;
		}
	}

	return std::stoi(report[lastLineStandingIndex], nullptr, 2);
}

void day3part2()
{
	auto report = parseBinFile("res/day3.txt");
	std::string dominantBits;

	std::cout << "oxygen generator rating" << std::endl;
	std::cout << getRating(report, dominantBits, Ratings::oxygen_generator) << std::endl;

	std::cout << "CO2 scrubber rating" << std::endl;
	std::cout << getRating(report, dominantBits, Ratings::C02_scrubber) << std::endl;

	int result = getRating(report, dominantBits, Ratings::oxygen_generator) * getRating(report, dominantBits, Ratings::C02_scrubber);

	std::cout << "The life support rating : " << result << std::endl;

}

void day3part1()
{
	auto v = parseBinFile("res/day3.txt");

	std::string dominantBits;
	findDominantBits(v, dominantBits);

	std::cout << dominantBits << std::endl;

	int gamma = std::stoi(dominantBits, nullptr, 2);

	// jouons avec les bits pour inverser la représentation binaire de gamma
	int masque = 0xFFF;			// pour ne garder que les 12 premiers bits 111111111111
	int epsilon = ~gamma & masque;

	std::cout << "gamma : " << gamma << std::endl;
	std::cout << "epsilon : " << epsilon << std::endl;
	std::cout << "gamma * epsilon bitwise  : " << gamma * epsilon << std::endl;
}

void runday3()
{
	day3part2();
}