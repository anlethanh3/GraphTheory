#include "Queue.h"

Queue::Queue()
{
	this->length = 0;
	this->pHead = NULL;
}

Queue::~Queue()
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
		
void Queue::EnQueue(SNode* node)
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

SNode* Queue::GetIndex(int index)
{
	SNode* temp = NULL;
	int i = 0;
	if(this->pHead != NULL)
	{
		temp = pHead;
		while(temp->pNext != NULL && i != index)
		{
			temp = temp->pNext;
			i++;
		}
	}
	return temp;
}

SNode* Queue::DeQueue()
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

int Queue::GetLength()
{
	return this->length;
}