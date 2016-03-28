#ifndef 	_ADJACENCYMATRIX_H_
#define _ADJACENCYMATRIX_H_

#include "AdjacencyGraph.h"

class AdjacencyMatrix : public AdjacencyGraph
{
	private:
		int n;
		bool** matrix;
	public:
		AdjacencyMatrix();
		~AdjacencyMatrix();
		
		int 		CountEdges();
		void 		GetDegrees(int*& degrees);
		int 		GetTypeOfGraph();
		
		void 		ConvertMatrix(const CGraph& graph);
		
		void 		ReadInput(char* file);
		void 		PrintOutput(char* file);
};

#endif