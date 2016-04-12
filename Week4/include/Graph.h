#ifndef  _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include "AdjacencyGraph.h"
#include "Prim.h"

class Graph
{
	public:
		AdjacencyGraph* adjGraph;
		Prim* prim;
	public:
		Graph();
		~Graph();
		
		void RunPrim();
		void WritePrim(std::ostream& outDevice);
		
		friend std::istream& operator >> (std::istream& inDevice, Graph& graph);
		friend std::ostream& operator << (std::ostream& outDevice, Graph& graph);
};

#endif