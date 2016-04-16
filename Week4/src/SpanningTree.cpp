#include "SpanningTree.h"

SpanningTree::SpanningTree()
{
}

SpanningTree::SpanningTree(const int& size)
{
	this->sum = 0;
	this->size = size;
	this->label = new int[size];
	for(int i=0; i<size; i++)
	{
		this->label[i] = 0;
	}
}

SpanningTree::~SpanningTree()
{
	this->sum = 0;
	delete []this->label;
	delete this->result;
	this->label = NULL;
	this->result = NULL;
}