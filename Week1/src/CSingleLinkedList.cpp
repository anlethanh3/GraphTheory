#include "CSingleLinkedList.h"
#include <iostream>

CSingleLinkedList::CSingleLinkedList()
{
	this->length = 0;
	this->pHead = NULL;
}

CSingleLinkedList::~CSingleLinkedList()
{
}
		
void CSingleLinkedList::Add(SNode* node)
{
	if(this->pHead == NULL)
	{
		this->pHead = node;
	}
	else
	{
		SNode* temp = this->pHead;
		while(temp->pNext != NULL)
		{
			temp = temp->pNext;
		}
		temp->pNext = node;
		node->pNext = NULL;
	}
	this->length++;
}

void CSingleLinkedList::Print()
{
	SNode* temp = this->pHead;
	while(temp != NULL)
	{
		std::cout << temp->value << " ";
		temp = temp->pNext;
	}
}

int CSingleLinkedList::GetLength()
{
	return this->length;
}