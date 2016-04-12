#ifndef  _SEDGE_H_
#define _SEDGE_H_

#ifndef NULL
#define NULL 0
#endif

struct SEdge
{
	int x;
	int y;
	int value;
	SEdge* pNext;
};

#endif