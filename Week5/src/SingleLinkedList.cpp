#include "SingleLinkedList.h"

SingleLinkedList::SingleLinkedList()
{
	this->length = 0;
	this->pHead = NULL;
	this->pTail = NULL;
}

SingleLinkedList::~SingleLinkedList()
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
	this->pHead = NULL;
	this->pTail = NULL;
}
		
void SingleLinkedList::Add(SNode* node)
{
	if(this->pHead == NULL)
	{
		this->pHead = node;
		this->pTail = node;
	}
	else
	{
		this->pTail->pNext = node;
		node->pNext = NULL;
		this->pTail = node;
	}
	this->length++;
}

int SingleLinkedList::GetLength()
{
	return this->length;
}

SNode* SingleLinkedList::GetIndex(int index)
{
	int i = 0;
	SNode* node = this->pHead;
	while(node->pNext != NULL && i != index)
	{
		node = node->pNext;
		i++;
	}
	return node;
}

bool SingleLinkedList::IsExistValue(int value)
{
	int i = 0;
	SNode* node = this->pHead;
	while(node != NULL)
	{
		if(node->value == value)
		{
			return true;
		}
		node = node->pNext;
	}
	return false;
}

int SingleLinkedList::GenerateValueNotInList()
{
	int i = 0;
	SNode* node = this->pHead;
	while(node != NULL)
	{
		if(node->value == i)
		{
			i = i + 1;
		}
		node = node->pNext;
	}
	return i;
}