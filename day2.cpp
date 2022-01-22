#include "day2.h"

/*
- get line
- split line by " "
- create Instruction
- create token string direction
- create token int distance
- apply Instruction
*/
Instruction instructionDecoder(const std::string& line, const char delimiter)
{
	Instruction instruction = { };
	size_t pos = 0;
	std::string direction = line.substr(0, line.std::string::find(delimiter));
	int distance = std::stoi(line.substr(line.std::string::find(delimiter), line.length()));

	if (direction == "forward")
		instruction.direction = Direction::forward;
	else if (direction == "up")
		instruction.direction = Direction::up;
	else
		instruction.direction = Direction::down;

	instruction.distance = distance;

	return instruction;
}

void instructionExec(Position& p, const Instruction i)
{
	switch (i.direction)
	{
	case Direction::forward:
		std::cout << "Going forward " << i.distance << std::endl;
		p.x += i.distance;
		p.y += p.aim * i.distance;
		break;
	case Direction::up:
		std::cout << "Going up " << i.distance << std::endl;
		p.aim -= i.distance;
		break;
	case Direction::down:
		std::cout << "Going down " << i.distance << std::endl;
		p.aim += i.distance;
		break;
	default:
		break;
	}
}

std::vector<std::string> parseFile(const char* path)
{
	std::fstream file;
	std::vector<std::string> v;
	file.open(path, std::ios::in);
	if (file.is_open())
	{
		std::string buffer;
		while (std::getline(file, buffer))
		{
			v.push_back(buffer);
			Instruction instruction = instructionDecoder(buffer, ' ');
		}
	}
	file.close();
	return v;
}

void runDay2Second()
{
	Position submarinePosition = { 0 };
	std::vector<std::string> v = parseFile("day2/day2.txt");
	for (const std::string& s : v)
	{
		instructionExec(submarinePosition, instructionDecoder(s, ' '));
	}
	std::cout << "Submarine final position :\n" << "Position : " << submarinePosition.x << "\nDepth : " << submarinePosition.y << std::endl;
	std::cout << "Resultat de l'exercice : position * depth = " << submarinePosition.x * submarinePosition.y << std::endl;
}


