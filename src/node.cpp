#include "node.h"

Node::Node(std::string c)
{
	name = c;
}

void Node::createEdge(int value, Node* nextNode)
{
	Edge v1;
	v1.configEdge(value, nextNode);
	vVector.push_back(v1);
}

void Node::createNode(int value)
{
	std::cout << "Created with value: " << value << std::endl;
}
