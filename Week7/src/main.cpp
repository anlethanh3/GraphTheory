#include <fstream>
#include "Graph.h"
#include <iostream>
#include <string>
//#include <ctime>

//void printtime()
//{
//	std::time_t result = std::time(0);
//    std::cout << std::asctime(std::localtime(&result)) << std::endl;
//}

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

	graph->RunEuler();

	fs.open(argv[2], std::fstream::out);
	graph->WriteEuler(fs);
	fs.close();
	
	delete graph;
	
	return 0;
}