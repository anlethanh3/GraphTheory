#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "SNode.h"

class Queue
{
	private:
		SNode* pHead;
		int length;
	public:
		Queue();
		~Queue();
		
		void 		EnQueue(SNode* node);
		SNode*	DeQueue();
		int 		GetLength();
};

#endif