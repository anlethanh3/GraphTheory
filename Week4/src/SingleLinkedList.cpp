#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList()
{
	this->length = 0;
	this->pHead = NULL;
}

SingleLinkedList::~SingleLinkedList()
{
	SEdge* temp = NULL;
	while(pHead)
	{
		temp = this->pHead;
		this->pHead = pHead->pNext;
		temp->pNext = NULL;
		temp->value = -1;
		delete temp;
		temp = NULL;
	}
}
		
void SingleLinkedList::Add(SEdge* node)
{
	if(this->pHead == NULL)
	{
		this->pHead = node;
	}
	else
	{
		SEdge* temp = this->pHead;
		while(temp->pNext != NULL)
		{
			temp = temp->pNext;
		}
		temp->pNext = node;
		node->pNext = NULL;
	}
	this->length++;
}

SEdge* SingleLinkedList::GetIndex(int index)
{
	SEdge* temp = NULL;
	int i = 0;
	if(this->pHead != NULL)
	{
		temp = this->pHead;
		while(temp->pNext != NULL && i != index)
		{
			temp = temp->pNext;
			i++;
		}
	}
	return temp;
}

int SingleLinkedList::GetLength()
{
	return this->length;
}