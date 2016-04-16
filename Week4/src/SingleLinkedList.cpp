#include "SingleLinkedList.h"
#include <iostream>

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

void SingleLinkedList::Sort()
{
	if(pHead == NULL)
	{
		return;
	}
	else
	{
		SEdge* temp = pHead;
		while(temp->pNext != NULL)
		{
			SEdge* min = temp;
			SEdge* temp2 = temp->pNext;
			while(temp2 != NULL)
			{
				if(temp2->value < min->value || (temp2->value == min->value && temp2->x < min->x))
				{
					min = temp2;
				}
				temp2 = temp2->pNext;
			}
			
			Swap(temp->x, min->x);
			Swap(temp->y, min->y);
			Swap(temp->value, min->value);
			
			temp = temp->pNext;
		}
	}
}

void SingleLinkedList::Swap(int& value1, int& value2)
{
	int temp = value1;
	value1 = value2;
	value2 = temp;
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

SEdge* SingleLinkedList::GetHead()
{
	return pHead;
}

void SingleLinkedList::RemoveHead()
{
	SEdge* temp;
	if(pHead)
	{
		temp = this->pHead;
		this->pHead = pHead->pNext;
		temp->pNext = NULL;
		this->length--;
		delete temp;
	}
}

int SingleLinkedList::GetLength()
{
	return this->length;
}