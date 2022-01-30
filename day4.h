#pragma once
#include "commoncpp.h"

#define BINGO_ROW_SIZE	5
#define BINGO_LINE_SIZE	5

typedef std::vector<std::vector<std::vector<int>>> BingoCards;

typedef struct {
	bool hasWon;
	int rank;
	size_t boardIndex;
	int tirage;
} WinningBoard;

void runday4();
std::vector<std::string> splitString(std::string& str, std::string delimiter);