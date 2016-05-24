#ifndef  _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include "AdjacencyGraph.h"
#include "Hamilton.h"

class Graph
{
	public:
		AdjacencyGraph* adjGraph;
		Hamilton* hamilton;
		int start;
	public:
		Graph();
		~Graph();

		void RunHamilton(bool isCycle);
		void WriteHamilton(std::ostream& outDevice);
		
		friend std::istream& operator >> (std::istream& inDevice, Graph& graph);
		friend std::ostream& operator << (std::ostream& outDevice, Graph& graph);
};

#endif