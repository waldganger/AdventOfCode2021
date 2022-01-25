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
			zeroCount == oneCount ? eqChecker.push_back('=') : eqChecker.push_back(' ');
		}
		bitString.push_back(zeroCount > oneCount ? '0' : '1');
	}
}

std::string getRating(const std::vector<std::string>& report, const std::string& dominantBits, const std::string& eqChecker, Ratings method)
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
				if (goodLinesRemaining <= 1) { return report[l]; }
				std::string temp(1, report[l][c]);
				if (std::stoi(temp) == 0)
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
				if (goodLinesRemaining <= 1) { return report[l]; }

				if (report[l][c] != dominantBits[c])
				{
					linesToKeep[l] = false;
					goodLinesRemaining--;
				}
			}
		}

	}

	int result = 0;
	for (auto l : linesToKeep)
	{
		result += l;
	}

	return "neh";
}

void day3part2()
{
	auto report = parseBinFile("res/day3.txt");
	std::string dominantBits;
	std::string eqChecker = findDominantBits(report, dominantBits);
	std::cout << dominantBits << std::endl;

	std::cout << getRating(report, dominantBits, eqChecker, Ratings::oxygen_generator) << std::endl;
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