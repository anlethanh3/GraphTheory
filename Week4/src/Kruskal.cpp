#include "Kruskal.h"

Kruskal::Kruskal()
{
}

Kruskal::Kruskal(const int& size)
{
	this->sum = 0;
	this->size = size;
	this->label = new int[size];
	for(int i=0; i<size; i++)
	{
		this->label[i] = i;
	}
	this->result = new SingleLinkedList();
}

Kruskal::~Kruskal()
{
}

void Kruskal::Run(MinHeap* heapEdge)
{
	while(this->result->GetLength() != this->size -1 && heapEdge->GetMin() != NULL)
	{
		SEdge* edge = heapEdge->RemoveMin();
		if(this->label[edge->x] != this->label[edge->y])
		{
			int min = this->label[edge->x] < this->label[edge->y] ? this->label[edge->x] : this->label[edge->y];
			int max = this->label[edge->x] > this->label[edge->y] ? this->label[edge->x] : this->label[edge->y];

			for(int j=0; j<this->size; j++)
			{
				if(this->label[j] == max)
				{
					this->label[j] = min;
				}
			}
			SEdge* temp = new SEdge();
			temp->x = edge->x;
			temp->y = edge->y;
			temp->value = edge->value;
			this->result->Add(temp);
			this->sum += temp->value;
		}
		delete edge;
	}
}