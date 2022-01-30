#pragma once
#include "commoncpp.h"
#include "day4.h"

typedef struct {
	int x1;
	int y1;
	int x2;
	int y2;
} Line;



class Day5
{
public:
	Day5(const char* path) : m_filePath{ path } { readFile(); populateVents(); }		// constructor: acquire resources
	~Day5() {}

	void readFile();
	void populateVents();
	void displayFileContents() const;
	void displayVentsCoordinates() const;
private:
	const char* m_filePath;
	std::vector<std::string> m_fileContents;
	std::vector<Line> m_vents;
};
void runDay5();