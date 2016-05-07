#ifndef  _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include "AdjacencyGraph.h"
#include "Dijkstra.h"

class Graph
{
	public:
		AdjacencyGraph* adjGraph;
		Dijkstra* dijktra;
		int start;
		int goal;
	public:
		Graph();
		~Graph();
		
		void RunDijktra(int start, int goal);
		void WriteDijktra(std::ostream& outDevice, int start, int goal);
		
		friend std::istream& operator >> (std::istream& inDevice, Graph& graph);
		friend std::ostream& operator << (std::ostream& outDevice, Graph& graph);
};

#endif