#ifndef _ADJACENCYLIST_H_
#define _ADJACENCYLIST_H_

#include "AdjacencyGraph.h"
#include "CSingleLinkedList.h"
class AdjacencyList : public AdjacencyGraph
{
	private:
		int n;
		int m;
		CSingleLinkedList* list;
	public:
		AdjacencyList();
		~AdjacencyList();
		
		int 		CountEdges();
		char* 	PrintDegree();
		int 		TypeOfGraph();
		
		void 		ReadInput(char* file);
		void 		PrintOutput(char* file);
};

#endif