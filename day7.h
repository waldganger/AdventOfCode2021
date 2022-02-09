#pragma once
#include "commoncpp.h"

// 1. Calculer la valeur médiane
// 2. Trouver le nombre commun le plus proche de la médiane

class Day7
{
public:
	Day7(const char* path);
	~Day7() {};

	uint32_t getMean() const;

private:
	const char* m_filePath;
	std::vector<uint32_t> m_positions;
};




void runDay7();