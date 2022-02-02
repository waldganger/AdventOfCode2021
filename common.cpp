#include "commoncpp.h"

std::vector<std::string> readFile(const char* path)
{
	std::vector <std::string> result;
	std::ifstream file;
	file.open(path, std::ios::in);
	if (file.is_open())
	{
		std::string buffer;
		while (std::getline(file, buffer))
		{
			result.push_back(buffer);
		}
	}
	file.close();
	return result;
}

std::vector<std::string> splitString(const std::string& str, std::string delimiter)
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