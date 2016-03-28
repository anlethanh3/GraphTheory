#ifndef  _SPOINT_H_
#define _SPOINT_H_

#ifndef NULL
#define NULL 0
#endif

struct SPoint
{
	int x;
	int y;
	SPoint* pNext;
};

#endif