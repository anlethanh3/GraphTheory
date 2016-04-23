#include "Coloring.h"
#include "SVertex.h"

Coloring::Coloring()
{
	this->numColor = 0;
	this->numVertex = 0;
	this->colors = new int[this->numVertex];
}

Coloring::Coloring(const int& numVertex)
{
	this->numColor = 0;
	this->numVertex = numVertex;
	this->lists = new SingleLinkedList[numVertex];
	this->colors = new int[numVertex];
	for(int i=0; i < numVertex; i++)
	{
		this->colors[i] = -1;
	}
}

Coloring::~Coloring()
{
	this->numColor = 0;
	delete[] this->lists;
	delete[] this->colors;
	this->lists = NULL;
	this->colors = NULL;
}

void Coloring::Run(SingleLinkedList* adjList)
{
	SVertex** listVertex = new SVertex*[this->numVertex];
	SVertex** vertexPointers = new SVertex*[this->numVertex];
	for(int i=0; i < this->numVertex; i++)
	{
		SVertex* vertex = new SVertex();
		vertex->index = i;
		vertex->value = adjList[i].GetLength();
		listVertex[i] = vertex;
		vertexPointers[i] = vertex;
	}
	int max = -1;
	for(int i=0; i < this->numVertex; i++)
	{
		max = i;
		for(int j=i+1; j < this->numVertex; j++)
		{
			if(listVertex[max]->value < listVertex[j]->value)
			{
				max = j;
			}
			else if(listVertex[max]->value == listVertex[j]->value && listVertex[max]->index > listVertex[j]->index)
			{
				max = j;
			}
		}
		SVertex* vertex = listVertex[i];
		listVertex[i] = listVertex[max];
		listVertex[max] = vertex;
		
		vertex = listVertex[i];
		int color = 0;
		while(this->lists[vertex->index].IsExistValue(color))
		{
			color++;
		}
		if(color > this->numColor)
		{
			this->numColor = color;
		}
		this->colors[vertex->index] = color;
		for(int j=0; j < adjList[vertex->index].GetLength(); j++)
		{
			SNode* node = adjList[vertex->index].GetIndex(j);
			if(this->colors[node->value] == -1)
			{
				SNode* node2 = new SNode();
				node2->value = color;
				if(this->lists[node->value].IsExistValue(color) == false)
				{
					this->lists[node->value].Add(node2);
				}
				vertexPointers[node->value]->value--;
			}
		}
	}
	this->numColor++;
	for(int i=0; i < this->numVertex; i++)
	{
		delete vertexPointers[i];
	}
	delete[] vertexPointers;
	delete[] listVertex;
}

void Coloring::Write(std::ostream& outDevice)
{
	outDevice << this->numColor << std::endl;
	for(int i=0; i < this->numVertex; i++)
	{
		outDevice << this->colors[i] << " ";
	}
}