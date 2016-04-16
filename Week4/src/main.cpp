#include <fstream>
#include "Graph.h"
#include <iostream>
#include <string>
#include <ctime>

int main(int argc, char** argv)
{	
	if(argc != 4)
	{
		return 1;
	}
	
	
	std::time_t result = std::time(0);
    std::cout << std::asctime(std::localtime(&result)) << result << std::endl;
	
	std::fstream fs;
	Graph* graph = new Graph();
	
	fs.open(argv[2], std::fstream::in);
	fs >> *graph;
	fs.close();
	
	result = std::time(0);
    std::cout << std::asctime(std::localtime(&result)) << result << std::endl;
	
	bool isPrim = std::string(argv[1]) == "prim" ? 1 : 0;
	graph->Run(isPrim);
	
	result = std::time(0);
    std::cout << std::asctime(std::localtime(&result)) << result << std::endl;
	
	fs.open(argv[3], std::fstream::out);
	graph->Write(fs);
	fs.close();
	
	delete graph;
	
	result = std::time(0);
    std::cout << std::asctime(std::localtime(&result)) << result << std::endl;
	
	return 0;
}