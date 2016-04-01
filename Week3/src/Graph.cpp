#include "Graph.h"
#include "AdjacencyMatrix.h"
#include "BFS.h"
#include "DFS.h"

Graph::Graph()
{
}

Graph::~Graph()
{
	delete this->adjGraph;
	delete this->search;
}

void Graph::Search(char* theory)
{
	int size = this->adjGraph->GetNumVertex();
	int index = 0;
	int* connected = new int[size];
	int numConnected = 1;
	for(int i=0; i < size; i++)
	{
		connected[i] = 0;
	}
	AdjacencyMatrix* adjMatrix = static_cast<AdjacencyMatrix*>(this->adjGraph);
	switch(theory[0])
	{
		case 'b':
			this->search = new BFS(size);
			break;
		case 'd':
			this->search = new DFS(size);
			break;
	}
	while(index != -1)
	{
		index = -1;
		for(int i=0; i< size; i++)
		{
			if(this->search->GetLabel(i)==0)
			{
				index = i;
				break;
			}
		}
		if(index != -1)
		{
			this->search->Run(adjMatrix->GetMatrix(), size, index);
			for(int i=0; i < size; i++)
			{
				if(this->search->GetLabel(i)==1 && connected[i] == 0)
				{
					connected[i] = numConnected;
				}
			}
		}
		numConnected++;
	}
	for(int i=0; i < size; i++)
	{
		std::cout<<connected[i]<< " ";
	}
	std::cout<<std::endl;
}

std::istream& operator >> (std::istream& inDevice, Graph& graph)
{
	int n = 0;
	inDevice >> n;
	graph.adjGraph = new AdjacencyMatrix(n);
	inDevice >> *graph.adjGraph;
	return inDevice;
}

std::ostream& operator << (std::ostream& outDevice, const Graph& graph)
{
	outDevice << graph.adjGraph<< std::endl;
	return outDevice;
}