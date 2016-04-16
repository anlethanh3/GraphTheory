#ifndef  _SPANNINGTREE_H_
#define _SPANNINGTREE_H_

#include "SingleLinkedList.h"
#include <iostream>

class SpanningTree
{
	protected:
		int* label;
		int size;
		SingleLinkedList* result;
		int sum;
	public:
		SpanningTree();
		SpanningTree(const int& size);
		virtual ~SpanningTree();
		
		virtual void Run(SingleLinkedList* list, int start) = 0;
		virtual void Write(std::ostream& outDevice);
};

#endif