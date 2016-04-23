#include "AdjacencyGraph.h"

AdjacencyGraph::AdjacencyGraph()
{
	this->type = -1;
}

AdjacencyGraph::AdjacencyGraph(const int& numVertex, const int& numEdge)
{
	this->type = -1;
	this->numVertex = numVertex;
	this->numEdge = numEdge;
}

AdjacencyGraph::~AdjacencyGraph()
{
	this->type = -1;
	this->numVertex = 0;
	this->numEdge = 0;
}

int AdjacencyGraph::GetNumVertex()
{
	return this->numVertex;
}

int AdjacencyGraph::GetNumEdge()
{
	return this->numEdge;
}

int AdjacencyGraph::GetType()
{
	return this->type;
}


std::istream& operator >> (std::istream& inDevice, AdjacencyGraph& graph)
{
	graph.Read(inDevice);
	return inDevice;
}

std::ostream& operator << (std::ostream& outDevice, AdjacencyGraph& graph){
	graph.Write(outDevice);
	return outDevice;
}