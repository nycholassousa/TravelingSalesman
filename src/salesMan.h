#ifndef SALESMAN_H
#define SALESMAN_H

#include <iostream>
#include <vector>
#include "graph.h"

class SalesMan{
	public:
		Graph* graph;
		std::vector<int> bestPath;
		int startedNodeIndex;
		int minorPath;
		SalesMan(Graph*);
		int calculateMin(std::vector<int>);
		int executeAlgorihm(int, std::vector<int>);
		void startAlgorithm(int);
		void copyVectors(std::vector<int>, std::vector<int>*, int);
};

#endif
