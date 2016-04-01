#include <fstream>
#include "Graph.h"

int main(int argc, char** argv)
{	
	if(argc != 4)
	{
		return 1;
	}
	
	std::fstream fs;
	Graph* graph = new Graph();
	
	fs.open(argv[2], std::fstream::in);
	fs >> *graph;
	fs.close();
	
	graph->Search(argv[1]);
	
	delete graph;
	
	return 0;
}