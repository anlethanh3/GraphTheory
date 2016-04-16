#ifndef  _SEDGE_H_
#define _SEDGE_H_

#ifndef NULL
#define NULL 0
#endif
#include <iostream>
struct SEdge
{
	int x;
	int y;
	int value;
	SEdge* pNext;
	
	bool operator>(const SEdge& a)
	{
		return this->value > a.value;
	}
	bool operator<=(const SEdge& a)
	{
		return this->value <= a.value;
	}
};

#endif