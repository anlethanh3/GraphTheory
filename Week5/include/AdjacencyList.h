#ifndef _ADJACENCYLIST_H_
#define _ADJACENCYLIST_H_

#include "AdjacencyGraph.h"
#include "SingleLinkedList.h"

class AdjacencyList : public AdjacencyGraph
{
	private:
		SingleLinkedList* lists;
	public:
		AdjacencyList();
		AdjacencyList(const int& numVertex, const int& numEdge);
		~AdjacencyList();
		
		SingleLinkedList* GetLists();
		
		void 		Read(std::istream& inDevice);
		void 		Write(std::ostream& outDevice);
};

#endif