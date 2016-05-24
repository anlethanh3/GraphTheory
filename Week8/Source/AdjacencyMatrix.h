#ifndef _ADJACENCYMATRIX_H_
#define _ADJACENCYMATRIX_H_

#include "AdjacencyGraph.h"
#include <iostream>

class AdjacencyMatrix : public AdjacencyGraph
{
	private:
		int** matrix;
	public:
		AdjacencyMatrix();
		AdjacencyMatrix(const int& numVertex, const int& numEdge);
		~AdjacencyMatrix();
		
		int GetType();
		int** GetMatrix();
		
		void Read(std::istream& inDevice);
		void Write(std::ostream& outDevice);
};

#endif