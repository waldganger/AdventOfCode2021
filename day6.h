#pragma once

#include "commoncpp.h"

class Day6
{
public:
	Day6(const char* path) : m_filePath(path), m_dayCounter(1) { populateFishes(); };
	~Day6() {};

	void populateFishes();
	void print() const;
	int doFishes(const int days);

private:
	const char* m_filePath;
	std::vector<std::vector<int>> m_fishesStates;
	int m_dayCounter;
};

void runDay6();