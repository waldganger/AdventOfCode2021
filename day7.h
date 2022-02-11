#pragma once
#include "commoncpp.h"
#include <algorithm>

// 1. Prendre conso = uint32::max
// 2. Prendre chaque valeur commme point de référence
// 3. Pour chaque valeur, calculer la distance avec le point de référence, et multiplier par nombre occurences => additionner le tout
// 2. Trouver le nombre commun le plus proche de la moyenne

#define MAX_LENGTH 10

typedef struct {
	uint32_t value;
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
	uint32_t computeBestSpot() const;

private:
	const char* m_filePath = NULL;
	std::vector<uint32_t> m_positions;
	std::vector<Occurence> m_SortedOccurences;
};




void runDay7();