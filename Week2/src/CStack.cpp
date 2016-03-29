#include "CStack.h"
#include <iostream>
CStack::CStack()
{
	this->length = 0;
	this->pHead = NULL;
}

CStack::~CStack()
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
		
void CStack::Push(SNode* node)
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

SNode*	CStack::GetTop()
{
	SNode* temp = pHead;
	while(temp->pNext != NULL)
	{
		temp = temp->pNext;
	}
	return temp;
}

void CStack::Pop()
{
	SNode* temp = pHead;
	if(temp == NULL)
	{
		return;
	}
	int i =0;
	while(temp != NULL && temp->pNext != NULL && temp->pNext->pNext != NULL)
	{
		temp = temp->pNext;
	}
	if(temp->pNext != NULL)
	{
		delete temp->pNext;
		temp->pNext = NULL;
		this->length--;
	}
	else if(temp != NULL && temp == pHead)
	{
		delete temp;
		pHead = NULL;
		temp = NULL;
		this->length--;
	}
}

int CStack::GetLength()
{
	return this->length;
}