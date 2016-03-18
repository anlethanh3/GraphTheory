#include "CSingleLinkedList.h"

CSingleLinkedList::CSingleLinkedList()
{
	this->length = 0;
	this->pHead = NULL;
}

CSingleLinkedList::~CSingleLinkedList()
{
	SNode* temp;
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

int CSingleLinkedList::GetLength()
{
	return this->length;
}