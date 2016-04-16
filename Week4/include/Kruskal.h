#ifndef  _KRUSKAL_H_
#define _KRUSKAL_H_

#include "SpanningTree.h"

class Kruskal : public SpanningTree
{
	public:
		Kruskal();
		Kruskal(const int& size);
		~Kruskal();
		
		void Run(SingleLinkedList* list, int start);
		void Write(std::ostream& outDevice);
};

#endif