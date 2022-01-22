#include <iostream>
#include <fstream>
#include <string>
#include <vector>


typedef struct {
	int h;
	int depth;
} Position;

int main()
{
	Position position = { 0 };

}

std::vector<std::string> parseFile(char* path)
{
	std::fstream file;
	std::vector<std::string> v;
	file.open(path, std::ios::in);
	if (file.is_open())
	{
		std::string buffer;
		while (std::getline(file, buffer))
		{
			std::cout << buffer << std::endl;
			v.push_back(buffer);
		}
	}

}

