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
		
void CQueue::EnQueue(SNode* node)
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

SNode* CQueue::DeQueue()
{
	SNode* temp;
	if(pHead)
	{
		temp = this->pHead;
		this->pHead = pHead->pNext;
		temp->pNext = NULL;
		this->length--;
	}
	return temp;
}

int CQueue::GetLength()
{
	return this->length;
}