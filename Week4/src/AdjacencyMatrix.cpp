#include "AdjacencyMatrix.h"
#include <fstream>

AdjacencyMatrix::AdjacencyMatrix()
{
	this->type = 1;
}

AdjacencyMatrix::AdjacencyMatrix(const int& numVertex, const int& numEdge) : AdjacencyGraph(numVertex, numEdge)
{
	this->type = 1;
	this->heapEdge = new MinHeap(this->numEdge);
	this->matrix = new int*[this->numVertex];
	for(int i = 0; i < this->numVertex; i++)
	{
		this->matrix[i] = new int[this->numVertex];
		for(int j = 0; j < this->numVertex; j++)
		{
			this->matrix[i][j] = 0;
		}
	}
}

AdjacencyMatrix::~AdjacencyMatrix()
{
	for(int i=0; i<this->numVertex;i++)
	{
		delete []this->matrix[i];
		this->matrix[i] = NULL;
	}
	delete []this->matrix;
	delete this->heapEdge;
	this->matrix = NULL;
	this->heapEdge = NULL;
}

int** AdjacencyMatrix::GetMatrix()
{
	return this->matrix;
}

MinHeap* AdjacencyMatrix::GetHeapEdge()
{
	return this->heapEdge;
}

void AdjacencyMatrix::Read(std::istream& inDevice)
{
	int temp[3] = {0, 0 ,0};
	for(int i = 0; i < this->numEdge; i++)
	{
		inDevice >> temp[0];
		inDevice >> temp[1];
		inDevice >> temp[2];
		this->matrix[temp[0]][temp[1]] = temp[2];
		this->matrix[temp[1]][temp[0]] = temp[2];
		
		SEdge* edge = new SEdge();
		edge->x = temp[0];
		edge->y = temp[1];
		edge->value = temp[2];
		this->heapEdge->Insert(edge);
	}
}

void AdjacencyMatrix::Write(std::ostream& outDevice)
{
	outDevice << this->numVertex << std::endl;
	for(int i = 0; i < this->numVertex; i++)
	{
		for(int j = 0; j < this->numVertex; j++)
		{
			outDevice << this->matrix[i][j] <<" ";
		}
		outDevice << std::endl;
	}
}