#include "day4.h"
#include <sstream>

std::vector<std::string> readFile(const char* path)
{
	std::vector<std::string> lines;
	std::ifstream file;
	file.open(path, std::ios::in);
	if (file.is_open())
	{
		std::string buffer;
		while (std::getline(file, buffer))
		{
			lines.push_back(buffer);
		}
	}
	return lines;
}

std::vector<std::string> splitString(std::string& str, std::string delimiter)
{
	size_t pos_start = 0;
	size_t pos_end = 0;
	size_t delim_len = delimiter.length();
	std::string token;
	std::vector<std::string> res;

	while ((pos_end = str.find(delimiter, pos_start)) != std::string::npos)
	{
		token = str.substr(pos_start, pos_end - pos_start);
		pos_start = pos_end + delim_len;
		res.push_back(token);
	}

	res.push_back(str.substr(pos_start));
	return res;
}

std::vector<int> getNumberLine(std::string& v, std::string delimiter)
{
	std::vector<int> result;
	std::vector strNumbers = splitString(v, delimiter);
	for (std::string& n : strNumbers)
	{
		if (n != delimiter && n != "") result.push_back(std::stoi(n));
	}
	return result;
}

std::vector<std::vector<std::vector<int>>> initBingoCards(std::vector<std::string>& v)
{
	std::vector<std::vector<int>> bingoCard;
	std::vector<std::vector<std::vector<int>>> bingoCards;

	for (size_t i = 1; i < v.size(); i++)
	{
		if (v[i] == "") continue;

		std::vector<int> bingoLine = getNumberLine(v[i], " ");
		bingoCard.push_back(bingoLine);

		if (bingoCard.size() == BINGO_LINE_SIZE)
		{
			bingoCards.push_back(bingoCard);
			bingoCard.clear();
		}
	}

	return bingoCards;
}

void runday4()
{
	std::cout << "Hello squid, wanna play bingo ?" << std::endl;
	std::string test = "yes";
	std::vector lines = readFile("res/day4.txt");
	std::vector<int> tirage = getNumberLine(lines[0], ",");
	std::vector<std::vector<std::vector<int>>> bingoCards = initBingoCards(lines);

	for (auto card : bingoCards)
	{
		for (auto line : card)
		{
			for (auto number : line)
			{
				std::cout << number << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}