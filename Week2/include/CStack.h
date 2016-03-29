#ifndef 	_CSTACK_H_
#define _CSTACK_H_

#include "SNode.h"

class CStack
{
	private:
		SNode* pHead;
		int length;
	public:
		CStack();
		~CStack();
		
		void 		Push(SNode* node);
		SNode*	GetTop();
		void		Pop();
		int 		GetLength();
};

#endif