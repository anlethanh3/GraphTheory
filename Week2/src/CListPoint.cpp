#include "CListPoint.h"

CListPoint::CListPoint()
{
	this->length = 0;
	this->pHead = NULL;
}

CListPoint::~CListPoint()
{
	SPoint* temp;
	while(pHead)
	{
		temp = this->pHead;
		this->pHead = pHead->pNext;
		temp->pNext = NULL;
		temp->x = temp->y = 0;
		delete temp;
		temp = NULL;
	}
}
		
void CListPoint::Add(SPoint* point)
{
	if(this->pHead == NULL)
	{
		this->pHead = point;
	}
	else
	{
		SPoint* temp = this->pHead;
		while(temp->pNext != NULL)
		{
			temp = temp->pNext;
		}
		temp->pNext = point;
		point->pNext = NULL;
	}
	this->length++;
}

int CListPoint::GetLength()
{
	return this->length;
}

int CListPoint::GetIndexOf(SPoint* point)
{
	int index = 0;
	SPoint* temp = this->pHead;
	while(temp)
	{
		if(temp->x == point->x && temp->y == point->y)
		{
			return index;
		}
		temp = temp->pNext;
		index++;
	}
	index = -1;
	return index;
}

SPoint*	CListPoint::GetPoint(int index)
{
	int i = 0;
	SPoint* temp = this->pHead;
	while(temp)
	{
		if(i == index)
		{
			return temp;
		}
		temp = temp->pNext;
		i++;
	}
	return temp;
}