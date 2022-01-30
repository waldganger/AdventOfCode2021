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

int checkWinner(const std::vector<std::vector<int>> bingoCard, const int tirage, WinningBoard& winningBoard)
{
	int markInRow = 0;
	int markInColumn = 0;

	for (size_t l = 0; l < BINGO_LINE_SIZE; l++)
	{
		markInRow = 0;
		for (size_t c = 0; c < BINGO_ROW_SIZE; c++)
		{
			if (bingoCard[l][c] == -1)
			{
				markInRow++;
				if (markInRow == BINGO_ROW_SIZE)
				{
					winningBoard.hasWon = true;
					winningBoard.tirage = tirage;
					return 1;
				}
			}
		}
	}
	for (size_t c = 0; c < BINGO_ROW_SIZE; c++)
	{
		markInColumn = 0;
		for (size_t l = 0; l < BINGO_LINE_SIZE; l++)
		{
			if (bingoCard[l][c] == -1)
			{
				markInColumn++;
				if (markInColumn == BINGO_LINE_SIZE)
				{
					winningBoard.hasWon = true;
					winningBoard.tirage = tirage;
					return 1;
				}
			}
		}
	}
	return 0;
}


std::vector<WinningBoard> boardMarker(BingoCards& bingocards, const std::vector<int>& tirages)
{
	int winnerCount = 0;
	std::vector<WinningBoard> winningBoards;
	winningBoards.reserve(bingocards.size());
	size_t cap = winningBoards.capacity();

	for (size_t i = 0; i < winningBoards.capacity(); i++)
	{
		winningBoards.push_back({ false, -1, 0, -1 });
	}

	for (const int& tirage : tirages)
	{
		for (size_t i = 0; i < bingocards.size(); i++) //std::vector<std::vector<int>>& card : bingocards
		{
			// Check si carte[i] a déjà gagné. Si oui, saute un tour.
			if (winningBoards[i].hasWon)
				continue;

			for (size_t l = 0; l < BINGO_LINE_SIZE; l++)
			{
				for (size_t c = 0; c < BINGO_ROW_SIZE; c++)
				{
					if (bingocards[i][l][c] == tirage)
					{
						bingocards[i][l][c] = -1;
					}
				}
			}
		}
		for (size_t i = 0; i < bingocards.size(); i++)
		{
			if (winningBoards[i].hasWon)
				continue;

			if (checkWinner(bingocards[i], tirage, winningBoards[i]))
			{
				winningBoards[i].rank = ++winnerCount;
				winningBoards[i].boardIndex = i;

				// c'était la dernière carte gagnante
				if (winnerCount == bingocards.size())
					return winningBoards;
			}
		}
	}

	// S'il n'y a pas de gagnant, c'est bizarre ! On retourne un WinninBoard avec tirage à -1;
	return winningBoards;
}

WinningBoard& computeLastWinningCard(const std::vector<WinningBoard>& winningBoards)
{
	for (auto w : winningBoards)
	{
		if (w.rank == 100)
			return w;
	}
}

int computeScore(const WinningBoard& winningBoard, const BingoCards& bingoCards)
{
	int unmarkedSum = 0;
	const int tirage = winningBoard.tirage;
	for (const std::vector<int> line : bingoCards[winningBoard.boardIndex])
	{
		for (const int& number : line)
		{
			unmarkedSum += (number == -1 ? 0 : number);
		}
	}
	return unmarkedSum * winningBoard.tirage;
}

void runday4()
{
	std::cout << "Hello squid, wanna play bingo ?" << std::endl;
	std::string test = "yes";
	std::vector lines = readFile("res/day4.txt");
	std::vector<int> tirage = getNumberLine(lines[0], ",");
	BingoCards bingoCards = initBingoCards(lines);

	const std::vector<WinningBoard> winningBoards = boardMarker(bingoCards, tirage);

	const WinningBoard lastBoard = computeLastWinningCard(winningBoards);

	int score = computeScore(lastBoard, bingoCards);

	std::cout << "La dernière carte est la " << lastBoard.boardIndex << std::endl;
	std::cout << "Le score de la carte est " << score << " avec le tirage " << lastBoard.tirage << std::endl;

}