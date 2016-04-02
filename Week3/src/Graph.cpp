#include "Graph.h"
#include "AdjacencyMatrix.h"
#include "BFS.h"
#include "DFS.h"
#include "Queue.h"

Graph::Graph()
{
}

Graph::~Graph()
{
	this->size = 0;
	this->numConnected = 0;
	delete this->adjGraph;
	delete this->search;
	delete[] this->connectedGraph;
}

void Graph::Search(char* theory)
{
	int index = 0;
	for(int i=0; i < this->size; i++)
	{
		this->connectedGraph[i] = 0;
	}
	AdjacencyMatrix* adjMatrix = static_cast<AdjacencyMatrix*>(this->adjGraph);
	switch(theory[0])
	{
		case 'b':
			this->search = new BFS(this->size);
			break;
		case 'd':
			this->search = new DFS(this->size);
			break;
	}
	if(this->search == NULL)
	{
		return;
	}
	while(index != -1)
	{
		index = -1;
		for(int i=0; i< this->size; i++)
		{
			if(this->search->GetLabel(i)==0)
			{
				index = i;
				break;
			}
		}
		if(index != -1)
		{
			this->numConnected++;
			this->search->Run(adjMatrix->GetMatrix(), this->size, index);
			for(int i=0; i < this->size; i++)
			{
				if(this->search->GetLabel(i)==1 && this->connectedGraph[i] == 0)
				{
					this->connectedGraph[i] = this->numConnected;
				}
			}
		}
	}
}

void Graph::PrintConnectedGraph(std::ostream& outDevice)
{
	SNode* node = NULL;
	Queue* queue = NULL;
	
	Queue** queues = new Queue*[this->numConnected];
	for(int i=0; i < this->numConnected; i++)
	{
		queues[i] = new Queue();
	}
	
	for(int i=0; i<this->size; i++)
	{
		node = new SNode();
		node->value = i;
		queues[this->connectedGraph[i] - 1]->EnQueue(node);
		node = NULL;
	}
	int min = -1;
	for(int i=0; i < this->numConnected - 1; i++)
	{
		min = i;
		for(int j=i+1; j < this->numConnected; j++)
		{
			if(queues[j]->GetLength() < queues[min]->GetLength())
			{
				min = j;
			}
		}
		queue = queues[i];
		queues[i] = queues[min];
		queues[min] = queue;
		queue = NULL;
	}
	
	outDevice << this->numConnected << std::endl;
	for(int i=0; i < this->numConnected; i++)
	{
		while(queues[i]->GetLength() != 0)
		{
			node = queues[i]->DeQueue();
			outDevice << node->value << " ";
			delete node;
			node = NULL;
		}
		outDevice << std::endl;
	}
	
	for(int i=0; i < this->numConnected; i++)
	{
		delete queues[i];
	}
	delete[] queues;
	queues = NULL;
}

std::istream& operator >> (std::istream& inDevice, Graph& graph)
{
	inDevice >> graph.size;
	graph.numConnected = 0;
	graph.connectedGraph = new int[graph.size];
	graph.adjGraph = new AdjacencyMatrix(graph.size);
	inDevice >> *graph.adjGraph;
	return inDevice;
}

std::ostream& operator << (std::ostream& outDevice, Graph& graph)
{
	graph.PrintConnectedGraph(outDevice);
	return outDevice;
}