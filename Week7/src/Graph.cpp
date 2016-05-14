#include "Graph.h"
#include "AdjacencyMatrix.h"

#ifndef NULL
#define NULL 0
#endif

Graph::Graph()
{
	this->euler = new Euler();
}

Graph::~Graph()
{
	delete this->adjGraph;
	delete this->euler;
}

void Graph::RunEuler()
{
	AdjacencyMatrix* matrixGraph = static_cast<AdjacencyMatrix*>(adjGraph);
	if (matrixGraph != NULL)
	{
		this->euler->Run(matrixGraph->GetMatrix(), matrixGraph->GetNumVertex(), matrixGraph->GetNumEdge());
	}
}

void Graph::WriteEuler(std::ostream& outDevice)
{
	this->euler->Write(outDevice);
}

std::istream& operator >> (std::istream& inDevice, Graph& graph)
{
	int numVertex = 0;
	int numEdge = 0;
	inDevice >> numVertex;
	inDevice >> numEdge;
	graph.adjGraph = new AdjacencyMatrix(numVertex, numEdge);
	inDevice >> *graph.adjGraph;
	return inDevice;
}

std::ostream& operator << (std::ostream& outDevice, Graph& graph)
{
	outDevice << *graph.adjGraph;
	return outDevice;
}