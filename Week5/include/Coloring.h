#ifndef _COLORING_H_
#define _COLORING_H_

#include "SingleLinkedList.h"
#include <iostream>
class Coloring
{
	private:
		SingleLinkedList* lists;
		int* colors;
		int numColor;
		int numVertex;
	public:
		Coloring();
		Coloring(const int& numVertex);
		~Coloring();
		
		void Run(SingleLinkedList* lists);
		void Write(std::ostream& outDevice);
};

#endif