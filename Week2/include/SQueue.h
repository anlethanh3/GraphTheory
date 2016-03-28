#ifndef 	_SQUEUE_H_
#define _SQUEUE_H_

#ifndef NULL
#define NULL 0
#endif

struct SQueue
{
	SQueue* pNext;
	int value;
	SQueue()
	{
		pNext 	= NULL;
		value 	= -1;
	}
};

#endif