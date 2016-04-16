#include "MinHeap.h"

#define LEFT(x)		(2*(x))
#define RIGHT(x)	(2*(x)+1)
#define PARENT(x)	((x)/2)

MinHeap::MinHeap()
{
}

MinHeap::MinHeap(int size)
{
	heap = new SEdge*[size + 1];
	index = 0;
}

MinHeap::~MinHeap()
{
	delete[] this->heap;
}

void MinHeap::Insert(SEdge* node)
{
	int j;
	j = (++index);

	heap[j] = node;
	HeapUp(j);
}

SEdge* MinHeap::GetMin()
{
	return heap[1];
}

SEdge* MinHeap::RemoveMin()
{
	SEdge* root;
	root = heap[1];

	index--;
	if (index == 0)
		return root;

	heap[1] = heap[index + 1];
	HeapDown(1);
	return root;
}

void MinHeap::HeapDown(int j)
{
	int best, r;
	SEdge* entry = heap[j];

	while (true)
	{
		best = LEFT(j);
		if (best > index)
			break;

		r = RIGHT(j);

		if (r <= index && *heap[best] > *heap[r])
			best = r;
		if (*entry <= *heap[best])
			break;

		heap[j] = heap[best];

		j = best;
	}

	heap[j] = entry;
}

void MinHeap::HeapUp(int &j)
{
	int p;
	SEdge* entry = heap[j];

	p = PARENT(j);
	while (p >= 1 && *heap[p] > *entry)
	{
		heap[j] = heap[p];
		j = p;
		p = PARENT(j);
	}

	heap[j] = entry;
}