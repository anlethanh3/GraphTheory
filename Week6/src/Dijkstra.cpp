#include "Dijkstra.h"
#include "SNode.h"
#include <queue>
#include <vector>
#include <string>

#ifndef MAX_INT
#define MAX_INT 2147483647
#endif

#ifndef NULL
#define NULL 0
#endif

Dijkstra::Dijkstra()
{
}

Dijkstra::Dijkstra(const int& size)
{
	this->size = size;
	this->label = new bool[size];
	this->previous = new int[size];
	this->value = new int[size];

	for (int i = 0; i < size; i++)
	{
		this->label[i] = 0;
		this->previous[i] = 0;
		this->value[i] = MAX_INT;
	}
}


Dijkstra::~Dijkstra()
{
	this->size = 0;
	delete[] this->label;
	delete[] this->previous;
	delete[] this->value;
	this->label = NULL;
	this->previous = NULL;
	this->value = NULL;
}

void Dijkstra::Run(int** matrix, int size, int start, int goal)
{
	std::priority_queue<SNode,std::vector<SNode>,SNode> pqueue;
	pqueue.push(SNode(start, -1, 0));
	while (!pqueue.empty())
	{
		SNode node(pqueue.top().index, pqueue.top().previous, pqueue.top().value);
		pqueue.pop();
		if (this->label[node.index] == 1) continue;
		for (int i = 0; i < size; i++)
		{
			if (matrix[node.index][i] != 0)
			{
				int cost = node.value + matrix[node.index][i];
				if (this->value[i] > cost)
				{
					pqueue.push(SNode(i, node.index, cost));
				}
			}
		}
		this->value[node.index] = node.value;
		this->previous[node.index] = node.previous;
		this->label[node.index] = 1;
	}
}

void Dijkstra::Write(std::ostream& outDevices, int start, int goal)
{
	std::string str = "";
	int i = goal;
	while (i != -1)
	{
		str = std::to_string(i) + " " + str;
		i = this->previous[i];
	}
	outDevices << this->value[goal] << std::endl;
	outDevices << str;
}