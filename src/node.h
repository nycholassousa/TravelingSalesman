#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>
#include <vector>
#include "edge.h"

class Node
{
	public:
		std::string name;
		int weight = 999999999;
		std::vector<Edge> vVector;
		Node(std::string name);
		void createEdge(int, Node*);
		void createNode(int value);
};

#endif
