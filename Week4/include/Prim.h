#ifndef  _PRIM_H_
#define _PRIM_H_

#include "SingleLinkedList.h"
#include <iostream>

class Prim
{
	private:
		int* label;
		int size;
		SingleLinkedList* result;
	public:
		Prim();
		Prim(const int& size);
		~Prim();
		
		void Run(SingleLinkedList* list, int start);
		void Write(std::ostream& outDevice);
};

#endif