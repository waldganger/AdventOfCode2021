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

void runday3()
{
	auto v = parseBinFile("res/day3.txt");
	const auto columnLenght = v.size();

	std::string dominantBits;

	for (size_t l = 0; l < LINE_LENGHT; l++)
	{
		int zeroCount = 0;
		int oneCount = 0;
		for (size_t c = 0; c < v.size(); c++)
		{
			switch (v[c][l])
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
		dominantBits.push_back(zeroCount > oneCount ? '0' : '1');
	}

	std::cout << dominantBits << std::endl;

	int gamma = std::stoi(dominantBits, nullptr, 2);

	// jouons avec les bits pour inverser la représentation binaire de gamma
	int masque = 0xFFF;			// pour ne garder que les 12 premiers bits 111111111111
	int epsilon = ~gamma & masque;

	std::cout << "gamma : " << gamma << std::endl;
	std::cout << "epsilon : " << epsilon << std::endl;
	std::cout << "gamma * epsilon bitwise  : " << gamma * epsilon << std::endl;
}