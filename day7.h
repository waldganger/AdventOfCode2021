#pragma once
#include "commoncpp.h"

// 1. Calculer la valeur m�diane
// 2. Trouver le nombre commun le plus proche de la m�diane

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