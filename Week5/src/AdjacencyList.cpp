#include "AdjacencyList.h"

AdjacencyList::AdjacencyList()
{
	this->type = 0;
}

AdjacencyList::~AdjacencyList()
{
	delete []this->lists;
	this->lists = NULL;
}

AdjacencyList::AdjacencyList(const int& numVertex, const int& numEdge) : AdjacencyGraph(numVertex, numEdge)
{
	this->type = 0;
	this->lists = new SingleLinkedList[this->numVertex];
}

SingleLinkedList* AdjacencyList::GetLists()
{
	return this->lists;
}

void AdjacencyList::Read(std::istream& inDevice)
{
	SNode* node = NULL;
	int temp[]={0, 0};
	for(int i = 0; i < this->numEdge; i++)
	{
		inDevice >> temp[0];
		inDevice >> temp[1];
		
		node = new SNode();
		node->pNext = NULL;
		node->value = temp[1];
		this->lists[temp[0]].Add(node);
		
		node = new SNode();
		node->pNext = NULL;
		node->value = temp[0];
		this->lists[temp[1]].Add(node);
	}
}

void AdjacencyList::Write(std::ostream& outDevice)
{
	outDevice << this->numVertex << " " << this->numEdge << std::endl;
	for(int i=0; i < this->numVertex; i++)
	{
		for(int j=0; j < this->lists[i].GetLength(); j++)
		{
			outDevice << i << " " << this->lists[i].GetIndex(j)->value << std::endl;
		}
	}
}