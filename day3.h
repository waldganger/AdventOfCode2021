#pragma once
#include "commoncpp.h"

#define LINE_LENGHT 12

typedef struct {
	bool gamma;
	bool epsilon;
	bool binaryRepresentation[LINE_LENGHT];
} Rate;

enum class Ratings
{
	C02_scrubber,
	oxygen_generator,

};

void runday3();