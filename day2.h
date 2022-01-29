#pragma once
#include "commoncpp.h"

typedef struct {
	int aim;
	int x;
	int y;
} Position;

enum class Direction
{
	forward,
	up,
	down
};

typedef struct {
	Direction direction;
	int distance;
} Instruction;


//Instruction instructionDecoder(const std::string& line, const char delimiter);
void runDay2Second();
std::vector<std::string> parseFile(const char* path);
