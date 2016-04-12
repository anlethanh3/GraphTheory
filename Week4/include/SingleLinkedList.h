#ifndef _SINGLELINDEDLIST_H_
#define _SINGLELINDEDLIST_H_

#include "SEdge.h"

class SingleLinkedList
{
	private:
		SEdge* pHead;
		int length;
	public:
		SingleLinkedList();
		~SingleLinkedList();
		
		void 		Add(SEdge* node);
		SEdge* GetIndex(int index);
		int 		GetLength();
};

#endif