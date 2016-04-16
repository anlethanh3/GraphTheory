#include "Prim.h"
#include "Queue.h"

Prim::Prim()
{
}

Prim::Prim(const int& size) : SpanningTree(size)
{
}

Prim::~Prim()
{
}

void Prim::Run(int** matrix, int size, int start)
{
	bool isStop = false;
	SEdge* edgeMin = NULL;
	this->label[start] = 1;
	Queue* queue = new Queue();
	SNode* node = new SNode();
	node->value = start;
	queue->EnQueue(node);
	while(this->result->GetLength() != this->size - 1 && isStop == false)
	{
		edgeMin = NULL;
		for(int i=0; i<queue->GetLength(); i++)
		{
			node = queue->GetIndex(i);
			for(int j=0; j < size; j++)
			{
				if(matrix[node->value][j] != 0 && this->label[j] == 0)
				{
					if(edgeMin == NULL)
					{
						edgeMin = new SEdge();
						edgeMin->x = node->value;
						edgeMin->y = j;
						edgeMin->value = matrix[node->value][j];
					}
					else
					{
						if(matrix[node->value][j] < edgeMin->value)
						{
							edgeMin->x = node->value;
							edgeMin->y = j;
							edgeMin->value = matrix[node->value][j];
						}
					}
				}
			}
		}
		if(edgeMin != NULL)
		{
			this->result->Add(edgeMin);
			this->sum += edgeMin->value;
			this->label[edgeMin->x] = 1;
			this->label[edgeMin->y] = 1;
			node = new SNode();
			node->value = edgeMin->y;
			queue->EnQueue(node);
		}
		else
		{
			isStop = true;
		}
	}
	delete queue;
}