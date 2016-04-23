#include "Graph.h"
#include "AdjacencyList.h"

Graph::Graph()
{
}

Graph::~Graph()
{
	delete this->adjGraph;
	delete this->coloring;
}

void Graph::RunColoring()
{
	this->coloring = new Coloring(this->adjGraph->GetNumVertex());
	AdjacencyList* adjList = static_cast<AdjacencyList*>(this->adjGraph);
	coloring->Run(adjList->GetLists());
}

void Graph::WriteColoring(std::ostream& outDevice)
{
	coloring->Write(outDevice);
}

std::istream& operator >> (std::istream& inDevice, Graph& graph)
{
	int numVertex = 0;
	int numEdge = 0;
	inDevice>>numVertex;
	inDevice>>numEdge;
	graph.adjGraph = new AdjacencyList(numVertex, numEdge);
	inDevice >> *graph.adjGraph;
	return inDevice;
}

std::ostream& operator << (std::ostream& outDevice, Graph& graph)
{
	outDevice << *graph.adjGraph;
	return outDevice;
}