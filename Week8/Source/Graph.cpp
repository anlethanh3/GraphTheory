#include "Graph.h"
#include "AdjacencyMatrix.h"

#ifndef NULL
#define NULL 0
#endif

Graph::Graph()
{
	this->hamilton = new Hamilton();
}

Graph::~Graph()
{
	delete this->adjGraph;
	delete this->hamilton;
}

void Graph::RunHamilton(bool isCycle)
{
	AdjacencyMatrix* matrixGraph = static_cast<AdjacencyMatrix*>(adjGraph);
	if (matrixGraph != NULL)
	{
		this->hamilton->Run(matrixGraph->GetMatrix(), matrixGraph->GetNumVertex(), this->start, isCycle);
	}
}

void Graph::WriteHamilton(std::ostream& outDevice)
{
	this->hamilton->Write(outDevice);
}

std::istream& operator >> (std::istream& inDevice, Graph& graph)
{
	int numVertex = 0;
	inDevice >> graph.start;
	inDevice >> numVertex;
	graph.adjGraph = new AdjacencyMatrix(numVertex, 0);
	inDevice >> *graph.adjGraph;
	return inDevice;
}

std::ostream& operator << (std::ostream& outDevice, Graph& graph)
{
	outDevice << *graph.adjGraph;
	return outDevice;
}