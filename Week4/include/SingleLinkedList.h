#ifndef _SINGLELINDEDLIST_H_
#define _SINGLELINDEDLIST_H_

#include "SEdge.h"

class SingleLinkedList
{
	private:
		SEdge* pHead;
		SEdge* pTail;
		int length;
	public:
		SingleLinkedList();
		~SingleLinkedList();
		
		void 		Add(SEdge* node);
		SEdge* GetIndex(int index);
		int 		GetLength();
		void 		Sort();
		SEdge* GetHead();
		void 		RemoveHead();
	private:
		void 		Swap(int& value1, int& value2);
};

#endif