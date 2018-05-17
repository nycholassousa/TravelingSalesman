#include "graph.h"

void Graph::createGraph(Node* node)
{
	this->nodeVector.push_back(node);
}

int Graph::getNodeByName(std::string name)
{
	for(int i=0; i<this->nodeVector.size(); i++)
		if(!name.compare(this->nodeVector[i]->name))
			return i;
		
	return -1;
}

int Graph::findNodeOnVector(Node* node)
{
	if(find(this->visitedNodes.begin(), this->visitedNodes.end(), node) != this->visitedNodes.end())
	{
		return 0;
	} else {
		return 1;
	}
}
