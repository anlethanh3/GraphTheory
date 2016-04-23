#ifndef  _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include "AdjacencyGraph.h"
#include "Coloring.h"

class Graph
{
	public:
		AdjacencyGraph* adjGraph;
		Coloring* coloring;
	public:
		Graph();
		~Graph();
		
		void RunColoring();
		void WriteColoring(std::ostream& outDevice);
		
		friend std::istream& operator >> (std::istream& inDevice, Graph& graph);
		friend std::ostream& operator << (std::ostream& outDevice, Graph& graph);
};

#endif