#ifndef _CQUEUE_H_
#define _CQUEUE_H_

#include "SNode.h"

class CQueue
{
	private:
		SNode* pHead;
		int length;
	public:
		CQueue();
		~CQueue();
		
		void 		EnQueue(SNode* node);
		SNode*	DeQueue();
		int 		GetLength();
};

#endif