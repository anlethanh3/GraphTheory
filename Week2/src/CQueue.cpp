#include "CQueue.h"

CQueue::CQueue()
{
	this->length = 0;
	this->pHead = NULL;
}

CQueue::~CQueue()
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
		
void CQueue::Add(SNode* node)
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

int CQueue::GetLength()
{
	return this->length;
}