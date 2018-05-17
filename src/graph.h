#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <algorithm>
#include "node.h"

class Graph{
	public:
		std::vector<Node*> nodeVector;
		std::vector<Node*> visitedNodes;
		void createGraph(Node*);
		int findNodeOnVector(Node*);
		int getNodeByName(std::string);
};

#endif
