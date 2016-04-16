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
}

Kruskal::~Kruskal()
{
}

void Kruskal::Run(SingleLinkedList* list, int start)
{
	this->result = new SingleLinkedList();
	SingleLinkedList* edges = new SingleLinkedList();
	for(int i=0; i<list->GetLength(); i++)
	{
		SEdge* edge = new SEdge();
		SEdge* temp = list->GetIndex(i);
		edge->x = temp->x;
		edge->y = temp->y;
		edge->value = temp->value;
		edges->Add(edge);
	}
	edges->Sort();
	while(this->result->GetLength() != this->size -1 || edges->GetLength() != 0)
	{
		SEdge* edge = edges->GetHead();
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
		edges->RemoveHead();
	}
	delete edges;
}

void Kruskal::Write(std::ostream& outDevice)
{
	SEdge* edgeTemp = NULL;
	outDevice<<this->sum<<std::endl;
	for(int i = 0; i < this->result->GetLength(); i++)
	{
		edgeTemp = this->result->GetIndex(i);
		outDevice<< "(" << edgeTemp->x << "," << edgeTemp->y << ") ";
	}
}