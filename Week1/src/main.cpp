#include <iostream>
#include <cstdlib>
#include "AdjacencyGraph.h"
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"


int main(int argc, char** argv)
{	
	if(argc != 4)
	{
		return 1;
	}
	int option =  atoi(argv[1]);
	
	AdjacencyGraph* graph;
	
	switch(option)
	{
		case 0:
			graph = new AdjacencyList();
			break;
		case 1:
			graph = new AdjacencyMatrix();
			break;
	}
	
	graph->ReadInput(argv[2]);
	graph->PrintOutput(argv[3]);
	return 0;
}