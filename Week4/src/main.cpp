#include <fstream>
#include "Graph.h"
#include <iostream>
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
	
	graph->RunPrim();
	
	fs.open(argv[3], std::fstream::out);
	graph->WritePrim(fs);
	fs.close();
	
	delete graph;
	
	return 0;
}