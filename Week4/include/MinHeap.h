#ifndef _MINHEAP_H_
#define _MINHEAP_H_

#include "SEdge.h"

class MinHeap
{
private:
	int index;
	SEdge** heap;
public:
	MinHeap();
	MinHeap(int size);
	~MinHeap();
	
	void Insert(SEdge* node);
	SEdge* GetMin();
	SEdge* RemoveMin();
	void HeapDown(int j);
	void HeapUp(int &j);
};

#endif