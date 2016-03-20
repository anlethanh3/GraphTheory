#ifndef 	_CSINGLELINDEDLIST_H_
#define _CSINGLELINDEDLIST_H_

#include "SNode.h"

class CSingleLinkedList
{
	private:
		SNode* pHead;
		int length;
	public:
		CSingleLinkedList();
		~CSingleLinkedList();
		
		void 		Add(SNode* node);
		int 		GetLength();
};

#endif