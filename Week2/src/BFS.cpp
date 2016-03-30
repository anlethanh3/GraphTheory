#include "BFS.h"
#include "CQueue.h"
#include "CStack.h"
#include <fstream>

BFS::BFS()
{
	
}

BFS::~BFS()
{
	this->size = 0;
	delete[] this->labels;
	this->labels = NULL;
}

BFS::BFS(const int& size)
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

void BFS::Run(int** matrix, int size, int start, int goal)
{
	int index = -1;
	CQueue* queue = new CQueue();
	SNode* node = new SNode();
	node->value = start;
	queue->EnQueue(node);
	while(queue->GetLength() != 0)
	{
		node = queue->DeQueue();
		index = node->value;
		this->labels[index] = 1;
		delete node;
		for(int i=0; i<size; i++)
		{
			if(matrix[index][i] == 1 && this->labels[i] == 0)
			{
				node = new SNode();
				node->value = i;
				queue->EnQueue(node);
				this->labels[i] = 1;
				this->previous[i] = index;
			}
		}
		node = NULL;
	}
	delete queue;
}

void BFS::PrintPath(CListPoint* points, int start, int goal, char* file)
{
	std::fstream fs;
	int n = points->GetLength();
	int index = goal;
	CStack* stack = new CStack();
	SNode* node = new SNode();
	node->value = index;
	stack->Push(node);
	node = NULL;
	while(previous[index] != -1 && stack->GetTop()->value != start)
	{
		node = new SNode();
		node->value = this->previous[index];
		stack->Push(node);
		node = NULL;
		index = this->previous[index];
	}
	fs.open(file, std::fstream::out);
	if(stack->GetTop()->value == start)
	{
		do
		{
			SNode* top = stack->GetTop();
			SPoint* point = points->GetPoint(top->value);
			fs<< "(" << point->x <<","<< point->y << ")" <<" ";
			stack->Pop();
		}
		while(stack->GetLength()>0);
	}
	else
	{
		fs<<"-1";
	}
	fs.close();
	delete stack;
	delete node;
}