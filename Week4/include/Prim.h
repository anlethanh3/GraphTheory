#ifndef  _PRIM_H_
#define _PRIM_H_

#include "SpanningTree.h"
#include <iostream>

class Prim : public SpanningTree
{
	public:
		Prim();
		Prim(const int& size);
		~Prim();
		
		void Run(SingleLinkedList* list, int start);
};

#endif