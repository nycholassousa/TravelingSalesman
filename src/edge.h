#ifndef EDGE_H
#define EDGE_H

#include <iostream>

class Node;

class Edge{
	public:
		int value = 0;
		Node* nextNode;
		void configEdge(int, Node*);
};

#endif
