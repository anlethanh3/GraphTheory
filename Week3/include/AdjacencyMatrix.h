#ifndef 	_ADJACENCYMATRIX_H_
#define _ADJACENCYMATRIX_H_

#include "AdjacencyGraph.h"
#include <iostream>

class AdjacencyMatrix : public AdjacencyGraph
{
	private:
		int n;
		int** matrix;
	public:
		AdjacencyMatrix();
		AdjacencyMatrix(const int& n);
		~AdjacencyMatrix();
		
		int 		CountEdges();
		void 		GetDegrees(int*& degrees);
		int 		GetTypeOfGraph();
		int 		GetType();
		
		void 		SetPath(int edge1, int edge2, bool hasPath);
		int** 	GetMatrix();
		int		GetNumVertex();
		
		void 		Read(std::istream& inDevice);
		void 		Write(std::ostream& outDevice);
};

#endif