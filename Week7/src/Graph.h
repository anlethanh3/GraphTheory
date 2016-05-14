#ifndef  _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include "AdjacencyGraph.h"
#include "Euler.h"

class Graph
{
	public:
		AdjacencyGraph* adjGraph;
		Euler* euler;
	public:
		Graph();
		~Graph();

		void RunEuler();
		void WriteEuler(std::ostream& outDevice);
		
		friend std::istream& operator >> (std::istream& inDevice, Graph& graph);
		friend std::ostream& operator << (std::ostream& outDevice, Graph& graph);
};

#endif