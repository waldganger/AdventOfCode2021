#pragma once
#include "commoncpp.h"
#include "day4.h"

typedef struct {
	int x1;
	int y1;
	int x2;
	int y2;
} Line;

typedef struct {
	int minX;
	int maxX;
	int minY;
	int maxY;
} EdgeCoordinates;



class Day5
{
public:
	Day5(const char* path) : m_filePath{ path } { readFile(); populateVents(); acquireEdgeCoordinates(); doDiagram(); }		// constructor: acquire resources
	~Day5() {}

	void readFile();
	void populateVents();
	void acquireEdgeCoordinates();
	void doDiagram();
	void displayFileContents() const;
	void displayVentsCoordinates() const;
	void displayDiagram() const;
	void overlap();


private:
	const char* m_filePath;
	std::vector<std::string> m_fileContents;
	std::vector<Line> m_vents;
	EdgeCoordinates m_edges;
	std::vector<std::vector<char>> m_diagram;
	int m_overlap;
};
void runDay5();