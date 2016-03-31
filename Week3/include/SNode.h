#ifndef 	_SNODE_H_
#define _SNODE_H_

#ifndef NULL
#define NULL 0
#endif

struct SNode
{
	SNode* pNext;
	int value;
	SNode()
	{
		pNext 	= NULL;
		value 	= -1;
	}
};

#endif