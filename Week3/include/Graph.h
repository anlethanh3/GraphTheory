#ifndef  _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include "AdjacencyGraph.h"
#include "Search.h"

class Graph
{
	public:
		AdjacencyGraph* adjGraph;
		Search* search;
	public:
		Graph();
		~Graph();
		
		void Search(char* theory);
		
		friend std::istream& operator >> (std::istream& inDevice, Graph& graph);
		friend std::ostream& operator << (std::ostream& outDevice, const Graph& graph);
};

#endif