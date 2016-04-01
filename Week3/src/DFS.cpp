#include "DFS.h"
#include "Stack.h"
#include <iostream>

DFS::DFS() 
	: Search()
{
}

DFS::DFS(const int& size)
	: Search(size)
{	
}

DFS::~DFS()
{
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
}