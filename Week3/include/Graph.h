#ifndef  _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include "AdjacencyGraph.h"

class Graph
{
	public:
		AdjacencyGraph* adjGraph;
	public:
		Graph();
		~Graph();
		
		void GenerateListPoint();
		void GenerateAdjacencyGraph();
		void RunBFS(char* file);
		void RunDFS(char* file);
		
		friend std::istream& operator >> (std::istream& inDevice, Graph& graph);
		friend std::ostream& operator << (std::ostream& outDevice, const Graph& graph);
};

#endif