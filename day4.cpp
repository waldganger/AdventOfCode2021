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

BingoCards initBingoCards(std::vector<std::string>& v)
{
	std::vector<std::vector<int>> bingoCard;
	BingoCards bingoCards;

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

WinningBoard checkWinner(const BingoCards& bingoCards, const int tirage)
{
	WinningBoard winningBoard = { 0 };
	int markInRow = 0;
	int markInColumn = 0;

	for (size_t i = 0; i < bingoCards.size(); i++)
	{
		for (size_t l = 0; l < BINGO_LINE_SIZE; l++)
		{
			markInRow = 0;
			for (size_t c = 0; c < BINGO_ROW_SIZE; c++)
			{
				if (bingoCards[i][l][c] == -1)
				{
					markInRow++;
					if (markInRow == BINGO_ROW_SIZE)
					{
						winningBoard.boardIndex = i;
						winningBoard.tirage = tirage;
						return winningBoard;
					}
				}
			}
		}
		for (size_t c = 0; c < BINGO_ROW_SIZE; c++)
		{
			markInColumn = 0;
			for (size_t l = 0; l < BINGO_LINE_SIZE; l++)
			{
				if (bingoCards[i][l][c] == -1)
				{
					markInColumn++;
					if (markInColumn == BINGO_LINE_SIZE)
					{
						winningBoard.boardIndex = i;
						winningBoard.tirage = tirage;
						return winningBoard;
					}
				}
			}
		}
	}

	winningBoard.tirage = -1;		// marque une erreur.
	return winningBoard;
}


WinningBoard boardMarker(BingoCards& bingocards, const std::vector<int>& tirages)
{
	for (const int& tirage : tirages)
	{
		for (std::vector<std::vector<int>>& card : bingocards)
		{
			for (std::vector<int>& line : card)
			{
				for (int& number : line)
				{
					if (number == tirage)
					{
						number = -1;
					}
				}
			}
		}
		// A chaque tirage, on regarde s'il y a un gagnant.
		return checkWinner(bingocards, tirage);
	}

	// S'il n'y a pas de gagnant, c'est bizarre ! On retourne un WinninBoard avec tirage à -1;
	WinningBoard erreur{ 0, -1 };
}



void runday4()
{
	std::cout << "Hello squid, wanna play bingo ?" << std::endl;
	std::string test = "yes";
	std::vector lines = readFile("res/day4.txt");
	std::vector<int> tirage = getNumberLine(lines[0], ",");
	BingoCards bingoCards = initBingoCards(lines);

	boardMarker(bingoCards, tirage);

	for (auto card : bingoCards)
	{
		for (auto line : card)
		{
			for (auto number : line)
			{
				std::cout << (number == -1 ? "X" : " ") << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}