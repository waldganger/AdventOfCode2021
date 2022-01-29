#include "day4.h"

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
	std::vector<std::string> result;
	size_t last = 0;
	size_t next = 0;
	std::string token;

	while ((next = str.find(delimiter, last)))
	{
		token = str.substr(last, next - last);
		result.push_back(token);
		if (next == std::string::npos) break;
		last = next + 1;
	}

	return result;
}

std::vector<int> initRandomNumbers(std::string& v)
{
	std::vector<int> result;
	std::vector strNumbers = splitString(v, ",");
	for (std::string& n : strNumbers)
	{
		//std::cout << n << std::endl;
		result.push_back(std::stoi(n));
	}
	return result;
}

void runday4()
{
	std::cout << "Hello squid, wanna play bingo ?" << std::endl;
	std::string test = "yes";
	std::vector lines = readFile("res/day4.txt");
	std::vector<int> tirage = initRandomNumbers(lines[0]);
}