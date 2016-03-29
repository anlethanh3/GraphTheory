#include "CGraph.h"
#include "AdjacencyMatrix.h"
#include "BFS.h"
#include <iostream>

CGraph::CGraph()
{
	this->points = new CListPoint();
}

CGraph::~CGraph()
{
	delete this->matrix;
	delete this->points;
	delete this->adjGraph;
}

void CGraph::GenerateListPoint()
{
	int m = this->matrix->GetSize();
	for(int i=0; i < m; i++)
	{
		for(int j=0; j < m; j++)
		{
			if(this->matrix->GetValue(i,j) == 0)
			{
				SPoint* point = new SPoint();
				point->x = i;
				point->y = j;
				this->points->Add(point);
			}
		}
	}
}

void CGraph::GenerateAdjacencyGraph()
{	
	int k = -1;
	int n = this->points->GetLength();
	int m = this->matrix->GetSize();
	
	SPoint p;
	SPoint* point;
	SPoint* arrPoint =  new SPoint[4];
	
	this->adjGraph = new AdjacencyMatrix(n);
	
	for(int i=0; i < n; i++)
	{
		point = this->points->GetPoint(i);
		
		arrPoint[0].x = point->x+1;
		arrPoint[0].y = point->y;
		
		arrPoint[1].x = point->x-1;
		arrPoint[1].y = point->y;
		
		arrPoint[2].x = point->x;
		arrPoint[2].y = point->y+1;
		
		arrPoint[3].x = point->x;
		arrPoint[3].y = point->y-1;
		
		for(int j = 0; j<4; j++)
		{
			if(arrPoint[j].x >= m || arrPoint[j].y >= m || 
				arrPoint[j].x < 0 || arrPoint[j].y < 0)
			{
				continue;
			}
			if(this->matrix->GetValue(arrPoint[j].x, arrPoint[j].y) == 0)
			{
				k = this->points->GetIndexOf(&arrPoint[j]);
				if(k != -1)
				{
					this->adjGraph->SetPath(i, k, 1);
					this->adjGraph->SetPath(k, i, 1);
				}
			}
		}
	}
	delete[] arrPoint;
	arrPoint = NULL;
	point = NULL;
}

void CGraph::RunBFS()
{
	int start = this->points->GetIndexOf(&this->start);
	int goal = this->points->GetIndexOf(&this->goal);
	BFS* bfs = new BFS(this->points->GetLength());
	AdjacencyMatrix* adjMatrix = NULL;
	if(this->adjGraph->GetType() == 1)
	{
		adjMatrix =  dynamic_cast<AdjacencyMatrix*>(this->adjGraph);
		bfs->Run(adjMatrix->GetMatrix(), adjMatrix->GetNumVertex(), start, goal);
		bfs->PrintPath(this->points, start, goal);
	}
	delete bfs;
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