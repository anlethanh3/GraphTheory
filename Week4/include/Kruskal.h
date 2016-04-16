#ifndef  _KRUSKAL_H_
#define _KRUSKAL_H_

#include "SpanningTree.h"
#include "MinHeap.h"
#include "SEdge.h"

class Kruskal : public SpanningTree
{
	public:
		Kruskal();
		Kruskal(const int& size);
		~Kruskal();
		
		void Run(MinHeap* heapEdge);
};

#endif