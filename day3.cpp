#include "day3.h"
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <fstream>


/*
- parse chaque ligne
- pour chaque caractère du string, push dans un array
- pour chaque colonne calculer bit dominant
- gamma, 12345
*/

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

int getRating(const std::vector<std::string>& report, const std::string& dominantBits, const std::string& eqChecker, Ratings method)
{
	std::vector<std::string> matchingNumbers;
	std::vector<bool> linesToKeep(report.size());
	int goodLinesRemaining = 0;
	for (auto l : linesToKeep)
	{
		l = true;
		goodLinesRemaining++;
	}

	for (size_t c = 0; c < dominantBits.length(); c++)
	{
		if (eqChecker[c] == '=')
		{
			for (size_t l = 0; l < report.size(); l++)
			{
				if (goodLinesRemaining <= 1) { return std::stoi(report[l], nullptr, 2); }
				std::string temp(1, report[l][c]);

				// If 0 and 1 are equally common, keep values with a 1 (oxygen generator) or a 0 (CO2 scrubber)  in the position being considered.
				if (std::stoi(temp) == (method == Ratings::oxygen_generator ? 0 : 1))
				{
					linesToKeep[l] = false;
					goodLinesRemaining--;
				}
			}
		}
		else
		{
			for (size_t l = 0; l < report.size(); l++)
			{
				if (goodLinesRemaining <= 1) { return std::stoi(report[l], nullptr, 2); }

				std::string temp(1, report[l][c]);
				std::string tempBitChar(1, dominantBits[c]);
				const int dominantBitToInt = std::stoi(tempBitChar);

				// depending on rating method, keep the most OR least common bit in the current bit position, and keep only lines with that bit in that position.
				int bitToKeep = (method == Ratings::oxygen_generator ? dominantBitToInt : (dominantBitToInt ? 0 : 1));

				if (std::stoi(temp) != bitToKeep)
				{
					linesToKeep[l] = false;
					goodLinesRemaining--;
				}
			}
		}

	}

	int result = 0;
	//for (auto l : linesToKeep)
	//{
	//	result += l;
	//}


	for (int i = 0; i < linesToKeep.size(); i++)
	{
		if (i) result = i;
	}

	return std::stoi(matchingNumbers[result], nullptr, 2);
}

void day3part2()
{
	auto report = parseBinFile("res/day3.txt");
	std::string dominantBits;
	std::string eqChecker = findDominantBits(report, dominantBits);
	std::cout << dominantBits << std::endl;
	std::cout << "Equality checker : " << "\"" << eqChecker << "\"" << std::endl;

	std::cout << "oxygen generator rating" << std::endl;
	std::cout << getRating(report, dominantBits, eqChecker, Ratings::oxygen_generator) << std::endl;

	std::cout << "CO2 scrubber rating" << std::endl;
	std::cout << getRating(report, dominantBits, eqChecker, Ratings::C02_scrubber) << std::endl;

	int result = getRating(report, dominantBits, eqChecker, Ratings::oxygen_generator) * getRating(report, dominantBits, eqChecker, Ratings::C02_scrubber);

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