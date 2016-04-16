#include "AdjacencyList.h"

AdjacencyList::AdjacencyList()
{
	this->type = 0;
}

AdjacencyList::~AdjacencyList()
{
	this->numVertex = -1;
	this->numEdge = -1;
	this->type = -1;
	delete []this->list;
	delete this->listEdge;
	this->list = NULL;
	this->listEdge = NULL;
}

SingleLinkedList* AdjacencyList::GetSingleLinkedList()
{
	return this->list;
}

SingleLinkedList* AdjacencyList::GetSingleLinkedListEdge()
{
	return this->listEdge;
}

int AdjacencyList::GetNumEdge()
{
	return this->numEdge;
}

void AdjacencyList::Read(std::istream& inDevice)
{
	SEdge* edge = NULL;
	int temp[3] = {0, 0, 0};
	inDevice >> this->numVertex;
	inDevice >> this->numEdge;
	this->list = new SingleLinkedList[this->numVertex];
	this->listEdge = new SingleLinkedList();
	
	for(int i = 0; i < this->numEdge; i++)
	{
		inDevice >> temp[0];
		inDevice >> temp[1];
		inDevice >> temp[2];
		
		edge = new SEdge();
		edge->x = temp[0];
		edge->y = temp[1];
		edge->value = temp[2];
		this->list[edge->x].Add(edge);
		
		edge = new SEdge();
		edge->x = temp[1];
		edge->y = temp[0];
		edge->value = temp[2];
		this->list[edge->x].Add(edge);
		
		edge = new SEdge();
		edge->x = temp[0];
		edge->y = temp[1];
		edge->value = temp[2];
		this->listEdge->Add(edge);
	}
}

void AdjacencyList::Write(std::ostream& outDevice)
{
	outDevice << this->numVertex<< " ";
	outDevice << this->numEdge<< std::endl;
	SEdge* edge = NULL;
	for(int i = 0; i < this->numVertex; i++)
	{
		for(int j = 0; j < this->list[i].GetLength(); j++)
		{
			edge = this->list[i].GetIndex(j);
			outDevice << edge->x << " " << edge->y << " " << edge->value << std::endl;
		}
	}
}