#ifndef _STACK_H_
#define _STACK_H_

#include "SNode.h"

class Stack
{
	private:
		SNode* pHead;
		int length;
	public:
		Stack();
		~Stack();
		
		void 		Push(SNode* node);
		SNode*	GetTop();
		void		Pop();
		int 		GetLength();
};

#endif