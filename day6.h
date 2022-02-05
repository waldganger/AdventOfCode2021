#pragma once

#include "commoncpp.h"

#define	TIMER_STATES 9

typedef struct {
	uint8_t status;
	uint64_t count;
} Timer;

class Day6
{
public:
	Day6(const char* path) : m_filePath(path), m_dayCounter(1) { initDataContainer(); populateFishes(); };
	~Day6() {};

	void initDataContainer();
	void populateFishes();
	void doFishes(const int days);
	uint64_t computePopulationSize() const;

private:
	const char* m_filePath;
	Timer m_fishesState[TIMER_STATES];
	int m_dayCounter;
};



void runDay6();
int flags();