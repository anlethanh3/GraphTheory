#include "CGraph.h"

CGraph::CGraph()
{
	
}

CGraph::~CGraph()
{
	delete this->matrix;
}

std::istream& operator >> (std::istream& inDevice, CGraph& graph)
{
	int n = 0;
	inDevice >> graph.start.x >> graph.start.y;
	inDevice >> graph.goal.x >> graph.goal.y;
	inDevice >> n;
	graph.matrix = new CMatrix(n);
	inDevice >> *graph.matrix;
	return inDevice;
}

std::ostream& operator << (std::ostream& outDevice, const CGraph& graph)
{
	outDevice << graph.start.x << " " << graph.start.y << " ";
	outDevice << graph.goal.x << " " << graph.goal.y << std::endl;
	outDevice << *graph.matrix;
	return outDevice;
}