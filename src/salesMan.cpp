#include "salesMan.h"

SalesMan::SalesMan(Graph* graph)
{
	this->graph = graph;
}

int SalesMan::calculateMin(std::vector<int> values)
{
	int minorValue = 999999999;
	for(int i = 0; i < values.size(); i++)
		if (values[i] < minorValue)
			minorValue = values[i];

	//std::cout << minorValue << std::endl;
	return minorValue;
}

void SalesMan::copyVectors(std::vector<int> v1, std::vector<int>* v2, int value)
{
	for (int i = 0; i < v1.size(); i++)
		if(v1[i] != v1[value])
			(*v2).push_back(v1[i]);
}

int SalesMan::executeAlgorihm(int nodeIndex, std::vector<int> nextNodesIndex)
{
	std::vector<int> distances;
	int distance;

	if(nextNodesIndex.size() == 0)
	{
		//std::cout << this->graph->nodeVector[nodeIndex]->vVector[this->startedNodeIndex].value << std::endl;
		return this->graph->nodeVector[nodeIndex]->vVector[this->startedNodeIndex].value;
	}

	if(nextNodesIndex.size() == 1)
	{
		std::vector<int> NextNodeMinusOne;
		distance = this->graph->nodeVector[nodeIndex]->vVector[nextNodesIndex[0]].value;
		//std::cout << distance << std::endl;
		copyVectors(nextNodesIndex, &NextNodeMinusOne, 0);
		
		//std::cout << (distance + executeAlgorihm(nextNodesIndex[0], NextNodeMinusOne)) << std::endl;
		return (distance + executeAlgorihm(nextNodesIndex[0], NextNodeMinusOne));
	}

	for(int i = 0; i < nextNodesIndex.size(); i++)
	{
		std::vector<int> NextNodeMinusOne;
		distance = this->graph->nodeVector[nodeIndex]->vVector[nextNodesIndex[i]].value;
		//std::cout << distance << std::endl;
		copyVectors(nextNodesIndex, &NextNodeMinusOne, i);
		distances.push_back(distance + executeAlgorihm(nextNodesIndex[i], NextNodeMinusOne));
	}
	
	return calculateMin(distances);
}

void SalesMan::startAlgorithm(int starting_with)
{
	std::vector<int> indexes;
	this->startedNodeIndex = starting_with;
	
	for (int i = 0; i < this->graph->nodeVector.size(); i++)
		if(starting_with != i)
			indexes.push_back(i);
		
	// for (std::vector<int>::const_iterator i = indexes.begin(); i != indexes.end(); ++i)
		// std::cout << *i << ' ';
	
	minorPath = executeAlgorihm(this->startedNodeIndex, indexes);
}
