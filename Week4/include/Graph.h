#ifndef  _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include "AdjacencyGraph.h"
#include "SpanningTree.h"

class Graph
{
	public:
		AdjacencyGraph* adjGraph;
		SpanningTree* minSpanningTree;
	public:
		Graph();
		~Graph();
		
		void Run(bool isPrim);
		void Write(std::ostream& outDevice);
		
		friend std::istream& operator >> (std::istream& inDevice, Graph& graph);
		friend std::ostream& operator << (std::ostream& outDevice, Graph& graph);
};

#endif