#ifndef _ADJACENCYLIST_H_
#define _ADJACENCYLIST_H_

#include "AdjacencyGraph.h"
#include "SingleLinkedList.h"
#include <iostream>

class AdjacencyList : public AdjacencyGraph
{
	private:
		SingleLinkedList* list;
		SingleLinkedList* listEdge;
		int numEdge;
	public:
		AdjacencyList();
		~AdjacencyList();
		
		SingleLinkedList* GetSingleLinkedList();
		SingleLinkedList* GetSingleLinkedListEdge();
		int GetNumEdge();
		
		void 		Read(std::istream& inDevice);
		void 		Write(std::ostream& outDevice);
};

#endif