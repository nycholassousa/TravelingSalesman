#include <iostream>
#include <fstream>
#include <sstream>
#include "src/graph.h"
#include "src/salesMan.h"

int main(int argc, char* argv[]){
	if (argc < 2)
    {
        std::clog << "Salesman [SAMPLE_FILE]" << std::endl;
        return EXIT_FAILURE;
    }

	//Use archive input to create graph
	std::ifstream file(argv[1], std::ios::in);
	std::string line;
	getline(file, line);
	std::stringstream ss(line);

	Graph* g1 = new Graph();
	int i;
	ss >> i;

	for(int j = 0; j < i; j++)
		g1->createGraph(new Node(std::to_string(j)));

	int lineCounter = 0;
	int columnCounter = 0;
	while(getline(file, line))
	{
		int value;
		columnCounter = 0;
		std::stringstream ss1(line);
		while(ss1 >> value)
		{
			g1->nodeVector[lineCounter]->createEdge(value, g1->nodeVector[columnCounter]);
			columnCounter++;
		}
		lineCounter++;
	}

	SalesMan* s1 = new SalesMan(g1);
	s1->startAlgorithm(0);
	std::cout << "Chosen File: " << argv[1] << std::endl;
	std::cout << "Minor Value: " << s1->minorPath << std::endl;

	return EXIT_SUCCESS;
}
