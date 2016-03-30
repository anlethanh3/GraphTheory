#ifndef  _CGRAPH_H_
#define _CGRAPH_H_

#include <iostream>
#include "CMatrix.h"
#include "AdjacencyGraph.h"
#include "CListPoint.h"

class CGraph
{
	public:
		CMatrix* matrix;
		SPoint start;
		SPoint goal;
		AdjacencyGraph* adjGraph;
		CListPoint* points;
	public:
		CGraph();
		~CGraph();
		
		void GenerateListPoint();
		void GenerateAdjacencyGraph();
		void RunBFS(char* file);
		
		friend std::istream& operator >> (std::istream& inDevice, CGraph& graph);
		friend std::ostream& operator << (std::ostream& outDevice, const CGraph& graph);
};

#endif