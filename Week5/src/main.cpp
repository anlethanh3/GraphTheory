#include <fstream>
#include <iostream>
#include <ctime>
#include "Graph.h"

void printtime()
{
	std::time_t result = std::time(0);
    std::cout << std::asctime(std::localtime(&result)) << std::endl;
}

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
	
	graph->RunColoring();
	
	fs.open(argv[2], std::fstream::out);
	graph->WriteColoring(fs);
	fs.close();
	
	delete graph;
	
	return 0;
}