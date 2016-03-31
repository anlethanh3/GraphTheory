#include "Graph.h"
#include <fstream>
int main(int argc, char** argv)
{	
	if(argc != 3)
	{
		return 1;
	}
	
	std::fstream fs;
	Graph* graph = new Graph();
	
	fs.open(argv[1], std::fstream::in);
	fs >> *graph;
	fs.close();
	graph->RunDFS(argv[2]);
	delete graph;
	return 0;
}