#include "BFS.h"
#include "Queue.h"
#include "Stack.h"

BFS::BFS()
	: Search()
{
}

BFS::BFS(const int& size)
	: Search(size)
{
}

BFS::~BFS()
{
}

void BFS::Run(int** matrix, int size, int start)
{
	int index = -1;
	Queue* queue = new Queue();
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

// void BFS::PrintPath(CListPoint* points, int start, int goal, char* file)
// {
	// std::fstream fs;
	// int n = points->GetLength();
	// int index = goal;
	// Stack* stack = new Stack();
	// SNode* node = new SNode();
	// node->value = index;
	// stack->Push(node);
	// node = NULL;
	// while(previous[index] != -1 && stack->GetTop()->value != start)
	// {
		// node = new SNode();
		// node->value = this->previous[index];
		// stack->Push(node);
		// node = NULL;
		// index = this->previous[index];
	// }
	// fs.open(file, std::fstream::out);
	// if(stack->GetTop()->value == start)
	// {
		// do
		// {
			// SNode* top = stack->GetTop();
			// SPoint* point = points->GetPoint(top->value);
			// fs<< "(" << point->x <<","<< point->y << ")" <<" ";
			// stack->Pop();
		// }
		// while(stack->GetLength()>0);
	// }
	// else
	// {
		// fs<<"-1";
	// }
	// fs.close();
	// delete stack;
	// delete node;
// }