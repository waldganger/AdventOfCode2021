#pragma once

#include "commoncpp.h"

#define	TIMER_STATES 9

class Day6
{
public:
	Day6(const char* path) : m_filePath(path), m_dayCounter(1), m_fishesState{ 0 } {  populateFishes(); };
	~Day6() {};

	void populateFishes();
	void doFishes(const int days);
	uint64_t computePopulationSize() const;

private:
	const char* m_filePath;
	uint64_t m_fishesState[TIMER_STATES];
	int m_dayCounter;
};


void runDay6();