#include "AdjacencyGraph.h"
#include "AdjacencyList.h"
#include "AdjacencyMatrix.h"

int main(int argc, char** argv)
{	
	if(argc != 4)
	{
		return 1;
	}
	
	AdjacencyGraph* graph = NULL;
	
	switch(argv[1][0])
	{
		case '0':
			graph = new AdjacencyList();
			break;
		case '1':
			graph = new AdjacencyMatrix();
			break;
	}
	if(graph != NULL)
	{
		graph->ReadInput(argv[2]);
		graph->PrintOutput(argv[3]);
		
		delete graph;
		graph = NULL;
	}
	else
	{
		return 1;
	}
	return 0;
}