#include "AdjacencyGraph.h"

AdjacencyGraph::AdjacencyGraph()
{
	this->type = -1;
}

AdjacencyGraph::~AdjacencyGraph()
{
	
}

int AdjacencyGraph::GetNumVertex()
{
	return this->size;
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