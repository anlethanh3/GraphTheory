#include "Graph.h"
#include "AdjacencyMatrix.h"

Graph::Graph()
{
}

Graph::~Graph()
{
	delete this->adjGraph;
	delete this->dijktra;
}

void Graph::RunDijktra(int start, int goal)
{
	this->dijktra = new Dijkstra(this->adjGraph->GetNumVertex());
	AdjacencyMatrix* adjMatrix = static_cast<AdjacencyMatrix*>(this->adjGraph);
	dijktra->Run(adjMatrix->GetMatrix(), adjMatrix->GetNumVertex(), start, goal);
}

void Graph::WriteDijktra(std::ostream& outDevice, int start, int goal)
{
	this->dijktra->Write(outDevice, start, goal);
}

std::istream& operator >> (std::istream& inDevice, Graph& graph)
{
	int numVertex = 0;
	int numEdge = 0;
	inDevice>>numVertex;
	graph.adjGraph = new AdjacencyMatrix(numVertex, numEdge);
	inDevice >> *graph.adjGraph;
	return inDevice;
}

std::ostream& operator << (std::ostream& outDevice, Graph& graph)
{
	outDevice << *graph.adjGraph;
	return outDevice;
}