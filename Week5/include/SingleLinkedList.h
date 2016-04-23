#ifndef _SINGLELINDEDLIST_H_
#define _SINGLELINDEDLIST_H_

#include "SNode.h"

class SingleLinkedList
{
	private:
		SNode* pHead;
		SNode* pTail;
		int length;
	public:
		SingleLinkedList();
		~SingleLinkedList();
		
		void 		Add(SNode* node);
		int 		GetLength();
		SNode* GetIndex(int index);
		bool 		IsExistValue(int value);
		int 		GenerateValueNotInList();
};

#endif