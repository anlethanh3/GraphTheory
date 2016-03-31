#include "Graph.h"
#include "AdjacencyMatrix.h"
#include "DFS.h"

Graph::Graph()
{
}

Graph::~Graph()
{
	delete this->adjGraph;
}

void Graph::RunBFS(char* file)
{
	// BFS* bfs = new BFS(this->points->GetLength());
	// AdjacencyMatrix* adjMatrix = NULL;
	// if(this->adjGraph->GetType() == 1)
	// {
		// adjMatrix =  dynamic_cast<AdjacencyMatrix*>(this->adjGraph);
		// bfs->Run(adjMatrix->GetMatrix(), adjMatrix->GetNumVertex(), start, goal);
		// bfs->PrintPath(this->points, start, goal, file);
	// }
	// delete bfs;
}

void Graph::RunDFS(char* file)
{
	AdjacencyMatrix* adjMatrix = NULL;
	if(this->adjGraph->GetType() == 1)
	{
		adjMatrix =  dynamic_cast<AdjacencyMatrix*>(this->adjGraph);
		DFS* dfs = new DFS(adjMatrix->GetNumVertex());
		dfs->Run(adjMatrix->GetMatrix(), adjMatrix->GetNumVertex(), 0);
		delete dfs;
	}
}

std::istream& operator >> (std::istream& inDevice, Graph& graph)
{
	int n = 0;
	inDevice >> n;
	graph.adjGraph = new AdjacencyMatrix(n);
	inDevice >> *graph.adjGraph;
	return inDevice;
}

std::ostream& operator << (std::ostream& outDevice, const Graph& graph)
{
	outDevice << graph.adjGraph<< std::endl;
	return outDevice;
}