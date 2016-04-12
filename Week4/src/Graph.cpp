#include "Graph.h"
#include "AdjacencyList.h"

Graph::Graph()
{
}

Graph::~Graph()
{
	delete this->adjGraph;
	delete this->prim;
}

void Graph::RunPrim()
{
	this->prim = new Prim(this->adjGraph->GetNumVertex());
	AdjacencyList* adjList = static_cast<AdjacencyList*>(this->adjGraph);
	this->prim->Run(adjList->GetSingleLinkedList(),0);
}

void Graph::WritePrim(std::ostream& outDevice)
{
	this->prim->Write(outDevice);
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