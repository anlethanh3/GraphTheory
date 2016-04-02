#include "Search.h"

#ifndef NULL
#define NULL 0
#endif

Search::Search()
{
}

Search::Search(const int& size)
{
	this->size = size;
	this->labels = new bool[this->size];
	this->previous = new int[this->size];
	for(int i=0; i<this->size; i++)
	{
		this->labels[i] = 0;
		this->previous[i] = -1;
	}
}

Search::~Search()
{
	delete[] this->labels;
	delete[] this->previous;
	this->labels = NULL;
	this->size = 0;	
}

bool Search::GetLabel(int index)
{
	return this->labels[index];
}

int Search::GetPrevious(int index)
{
	return this->previous[index];
}