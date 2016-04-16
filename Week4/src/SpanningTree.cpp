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
	this->result = new SingleLinkedList();
}

SpanningTree::~SpanningTree()
{
	this->sum = 0;
	delete []this->label;
	delete this->result;
	this->label = NULL;
	this->result = NULL;
}

void SpanningTree::Write(std::ostream& outDevice)
{
	SEdge* edgeTemp = NULL;
	if(this->result->GetLength())
	{
		outDevice<<this->sum<<std::endl;
		for(int i = 0; i < this->result->GetLength(); i++)
		{
			edgeTemp = this->result->GetIndex(i);
			outDevice<< "(" << edgeTemp->x << "," << edgeTemp->y << ") ";
		}
	}
	else
	{
		outDevice<<"NULL"<<std::endl;
	}
}