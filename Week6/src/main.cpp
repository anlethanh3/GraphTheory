#include <fstream>
#include "Graph.h"
#include <iostream>
#include <string>
#include <ctime>

void printtime()
{
	std::time_t result = std::time(0);
    std::cout << std::asctime(std::localtime(&result)) << std::endl;
}

int main(int argc, char** argv)
{	
	if(argc != 5)
	{
		return 1;
	}
	int start = atoi(argv[3]);
	int goal = atoi(argv[4]);
	std::fstream fs;
	Graph* graph = new Graph();
	
	fs.open(argv[1], std::fstream::in);
	fs >> *graph;
	fs.close();
	
	graph->RunDijktra(start, goal);

	fs.open(argv[2], std::fstream::out);
	graph->WriteDijktra(fs, start, goal);
	fs.close();
	
	delete graph;
	
	return 0;
}