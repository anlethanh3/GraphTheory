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

void Prim::Run(SingleLinkedList* list, int start)
{
	this->result = new SingleLinkedList();
	bool isStop = false;
	SEdge* edgeMin = NULL;
	SEdge* edgeTemp = NULL;
	this->label[start] = 1;
	Queue* queue = new Queue();
	SNode* node = new SNode();
	node->value = start;
	queue->EnQueue(node);
	while(this->result->GetLength() != this->size - 1 && isStop == false)
	{
		edgeTemp = NULL;
		edgeMin = NULL;
		for(int i=0; i<queue->GetLength(); i++)
		{
			node = queue->GetIndex(i);
			for(int j=0; j < list[node->value].GetLength(); j++)
			{
				edgeTemp = list[node->value].GetIndex(j);
				if(edgeMin == NULL)
				{
					if(this->label[edgeTemp->y] == 0 && this->label[edgeTemp->x] ==1)
					{
						edgeMin = edgeTemp;
					}
				}
				else
				{
					if(this->label[edgeTemp->y] ==0 && this->label[edgeTemp->x] ==1 && edgeTemp->value < edgeMin->value)
					{
						edgeMin = edgeTemp;
					}
				}
			}
		}
		if(edgeMin != NULL)
		{
			edgeTemp = new SEdge();
			edgeTemp->x = edgeMin->x;
			edgeTemp->y = edgeMin->y;
			edgeTemp->value = edgeMin->value;
			
			this->result->Add(edgeTemp);
			
			this->sum += edgeTemp->value;
			this->label[edgeTemp->x] = 1;
			this->label[edgeTemp->y] = 1;
			node = new SNode();
			node->value = edgeTemp->y;
			queue->EnQueue(node);
		}
		else
		{
			isStop = true;
		}
	}
	delete queue;
}

void Prim::Write(std::ostream& outDevice)
{
	SEdge* edgeTemp = NULL;
	outDevice<<this->sum<<std::endl;
	for(int i = 0; i < this->result->GetLength(); i++)
	{
		edgeTemp = this->result->GetIndex(i);
		outDevice<< "(" << edgeTemp->x << "," << edgeTemp->y << ") ";
	}
}