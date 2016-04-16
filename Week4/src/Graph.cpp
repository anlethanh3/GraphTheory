#include "Graph.h"
#include "AdjacencyList.h"
#include "Prim.h"
#include "Kruskal.h"

Graph::Graph()
{
}

Graph::~Graph()
{
	delete this->adjGraph;
	delete this->minSpanningTree;
}

void Graph::Run(bool isPrim)
{
	AdjacencyList* adjList = static_cast<AdjacencyList*>(this->adjGraph);
	if(isPrim == true)
	{
		this->minSpanningTree = new Prim(this->adjGraph->GetNumVertex());
		this->minSpanningTree->Run(adjList->GetSingleLinkedList(),0);
	}
	else
	{
		this->minSpanningTree = new Kruskal(this->adjGraph->GetNumVertex());
		this->minSpanningTree->Run(adjList->GetSingleLinkedListEdge(),0);
	}
}

void Graph::Write(std::ostream& outDevice)
{
	this->minSpanningTree->Write(outDevice);
}

std::istream& operator >> (std::istream& inDevice, Graph& graph)
{
	graph.adjGraph = new AdjacencyList();
	inDevice >> *graph.adjGraph;
	return inDevice;
}

std::ostream& operator << (std::ostream& outDevice, Graph& graph)
{
	outDevice << *graph.adjGraph;
	return outDevice;
}