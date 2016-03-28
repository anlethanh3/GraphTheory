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
		
		void 		Add(SNode* node);
		int 		GetLength();
};

#endif