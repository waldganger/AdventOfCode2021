#pragma once

#include "commoncpp.h"

typedef struct {
	uint8_t status;
	uint64_t count;
} Timer;

class Day6
{
public:
	Day6(const char* path) : m_filePath(path), m_dayCounter(1) { populateFishes(); };
	~Day6() {};

	void populateFishes();
	size_t doFishes(const int days);

private:
	const char* m_filePath;
	std::vector<uint8_t> m_fishesState;
	int m_dayCounter;
};



void runDay6();
int flags();