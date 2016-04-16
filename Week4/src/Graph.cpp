#include "Graph.h"
#include "AdjacencyMatrix.h"
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
	AdjacencyMatrix* adjMatrix = static_cast<AdjacencyMatrix*>(this->adjGraph);
	if(isPrim == true)
	{
		this->minSpanningTree = new Prim(this->adjGraph->GetNumVertex());
		Prim* prim = static_cast<Prim*>(this->minSpanningTree);
		prim->Run(adjMatrix->GetMatrix(),adjMatrix->GetNumVertex(),0);
	}
	else
	{
		this->minSpanningTree = new Kruskal(this->adjGraph->GetNumVertex());
		Kruskal* kruskal = static_cast<Kruskal*>(this->minSpanningTree);
		kruskal->Run(adjMatrix->GetHeapEdge());
	}
}

void Graph::Write(std::ostream& outDevice)
{
	this->minSpanningTree->Write(outDevice);
}

std::istream& operator >> (std::istream& inDevice, Graph& graph)
{
	int numVertex = 0;
	int numEdge = 0;
	inDevice>>numVertex;
	inDevice>>numEdge;
	graph.adjGraph = new AdjacencyMatrix(numVertex, numEdge);
	inDevice >> *graph.adjGraph;
	return inDevice;
}

std::ostream& operator << (std::ostream& outDevice, Graph& graph)
{
	outDevice << *graph.adjGraph;
	return outDevice;
}