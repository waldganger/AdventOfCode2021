#pragma once

#include "commoncpp.h"

class Day6
{
public:
	Day6(const char* path) : m_filePath{ path } { populateFishes(); };
	~Day6() {};

	void populateFishes();
	void print();

private:
	const char* m_filePath;
	std::vector<int> m_fishes;
};

void runDay6();