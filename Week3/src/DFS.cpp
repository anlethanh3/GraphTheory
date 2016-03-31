#include "DFS.h"
#include "Stack.h"
#include <iostream>
DFS::DFS()
{
	
}

DFS::DFS(const int& size)
{
	this->size = size;
	this->labels = new int[this->size];
	this->previous = new int[this->size];
	for(int i=0; i<this->size; i++)
	{
		this->labels[i] = 0;
		this->previous[i] = -1;
	}
}

DFS::~DFS()
{
	delete[] this->labels;
	delete[] this->previous;
	
	this->size = 0;
	this->labels = NULL;
	this->previous = NULL;
}

void DFS::Run(int** matrix, int size, int start)
{
	Stack* stack = new Stack();
	SNode* node = new SNode();
	node->value = start;
	stack->Push(node);
	node = NULL;
	int index = -1;
	bool hasPath = false;
	this->labels[start] = 1;
	while(stack->GetLength() != 0)
	{
		index = stack->GetTop()->value;
		hasPath = false;
		for(int i=0; i < size; i++)
		{
			if(matrix[index][i] == 1 && this->labels[i] == 0)
			{
				hasPath = true;
				this->previous[i] = index;
				this->labels[i] = 1;
				node = new SNode();
				node->value = i;
				stack->Push(node);
				break;
			}
		}
		if(hasPath == false)
		{
			stack->Pop();
		}
	}
	for(int i=0;i<size;i++)
	{
		std::cout<<this->labels[i]<<" ";
	}
	std::cout<<std::endl;
	for(int i=0;i<size;i++)
	{
		std::cout<<this->previous[i]<<" ";
	}
}