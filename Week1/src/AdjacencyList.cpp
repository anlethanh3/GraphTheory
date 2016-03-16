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
	for(int i=0; i<this->n;i++)
	{
		sum += this->list[i].GetLength();
	}
	return sum;
}

char* AdjacencyList::PrintDegree()
{
	char* buffer = new char[50];
	for(int i=0; i<this->n;i++)
	{
		sprintf(buffer,"%d %d",buffer,this->list[i].GetLength());
	}
	return buffer;
}

int AdjacencyList::TypeOfGraph()
{
	int result[2] = {0,0};
	for(int i=0; i<this->n;i++)
	{
		if(this->list[i].GetLength() == this->n - 1)
		{
			result[0]++;
		}
		else if(this->list[i].GetLength() == 2)
		{
			result[1]++;
		}
	}
	return 0;
}

void AdjacencyList::ReadInput(char* file)
{
	std::fstream fs;
	int temp = 0;
	fs.open(file,std::fstream::in);
	fs >> this->n;
	fs >> this->m;
	this->list = new CSingleLinkedList[this->n];
	for(int i=0; i<this->m; i++)
	{
		fs >> temp;
		SNode* node = new SNode();
		node->pNext = NULL;
		fs >> node->value;
		this->list[temp].Add(node);
	}
	fs.close();
	// for(int i =0; i<this->n; i++)
	// {
		// std::cout<<i<<" ";
		// this->list[i].Print();
		// std::cout<<std::endl;
	// }
}

void AdjacencyList::PrintOutput(char* file)
{
	
}