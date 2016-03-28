#include "CGraph.h"
#include "AdjacencyGraph.h"
#include "AdjacencyMatrix.h"
#include <fstream>
int main(int argc, char** argv)
{	
	if(argc != 3)
	{
		return 1;
	}
	
	std::fstream fs;
	CGraph* graph = new CGraph();
	
	fs.open(argv[1], std::fstream::in);
	fs >> *graph;
	fs.close();
	
	AdjacencyGraph* adjgraph = new AdjacencyMatrix();
	adjgraph->ConvertMatrix(*graph);
	
	adjgraph->PrintOutput(argv[2]);
	
	delete graph;
	delete adjgraph;
	return 0;
}