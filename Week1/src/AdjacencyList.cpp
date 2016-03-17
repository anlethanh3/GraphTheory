#include "AdjacencyList.h"
#include <iostream>
#include <fstream>
#include <cstdio>
AdjacencyList::AdjacencyList()
{
	this->type = 0;
}

AdjacencyList::~AdjacencyList()
{
	
}

int AdjacencyList::CountEdges()
{
	int sum = 0;
	for(int i = 0; i < this->n; i++)
	{
		sum += this->list[i].GetLength();
	}
	sum /= 2;
	return sum;
}

void AdjacencyList::GetDegrees(int*& degrees)
{
	degrees = new int[this->n];
	
	for(int i = 0; i < this->n; i++)
	{
		degrees[i] = this->list[i].GetLength();
	}
}

int AdjacencyList::GetTypeOfGraph()
{
	int result[3] = {0,0,0};
	for(int i = 0; i < this->n; i++)
	{
		if(this->list[i].GetLength() == this->n - 1)
		{
			result[0]++;
		}
		else if(this->list[i].GetLength() == 2)
		{
			result[1]++;
		}
		else if(this->list[i].GetLength() == 1)
		{
			result[2]++;
		}
	}
	if(result[0] == this->n)
	{
		return 1;
	}
	else if(result[1] == this->n)
	{
		return 2;
	}
	else if(result[0] == 1 && result[2] == this->n-1)
	{
		return 3;
	}
	return 0;
}

void AdjacencyList::ReadInput(char* file)
{
	std::fstream fs;
	SNode* node;
	int temp[2] = {-1,-1};
	fs.open(file, std::fstream::in);
	fs >> this->n;
	fs >> this->m;
	this->list = new CSingleLinkedList[this->n];
	for(int i = 0; i < this->m; i++)
	{
		fs >> temp[0];
		fs >> temp[1];
		
		node = new SNode();
		node->pNext = NULL;
		node->value 	= temp[1];
		this->list[temp[0]].Add(node);
		
		node = new SNode();
		node->pNext = NULL;
		node->value 	= temp[0];
		this->list[temp[1]].Add(node);
	}
	fs.close();
}

void AdjacencyList::PrintOutput(char* file)
{
	std::fstream fs;
	int* degrees;
	fs.open(file, std::fstream::out);
	fs << this->CountEdges() << std::endl;
	this->GetDegrees(degrees);
	for(int i=0; i < this->n; i++)
	{
		fs << degrees[i] << " ";
	}
	fs << std::endl;
	fs << this->GetTypeOfGraph();
	fs.close();
	delete []degrees;
	degrees = NULL;
}