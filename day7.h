#pragma once
#include "commoncpp.h"
#include <algorithm>

// 1. Calculer la valeur moyenne
// 2. Trouver le nombre commun le plus proche de la moyenne

#define MAX_LENGTH 10

typedef struct {
	uint32_t number;
	int counter;
} Occurence;

class Day7
{
public:
	Day7(const char* path);
	~Day7() {};

	uint32_t getMean() const;
	void detectAlignes();
	void printAlignes() const;

private:
	const char* m_filePath = NULL;
	std::vector<uint32_t> m_positions;
	std::vector<Occurence> m_occurences;
};




void runDay7();