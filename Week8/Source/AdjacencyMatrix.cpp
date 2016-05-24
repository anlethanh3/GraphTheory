#include "AdjacencyMatrix.h"
#include <fstream>

AdjacencyMatrix::AdjacencyMatrix()
{
	this->type = 1;
}

AdjacencyMatrix::AdjacencyMatrix(const int& numVertex, const int& numEdge) : AdjacencyGraph(numVertex, numEdge)
{
	this->type = 1;
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
	this->matrix = NULL;
}

int** AdjacencyMatrix::GetMatrix()
{
	return this->matrix;
}

void AdjacencyMatrix::Read(std::istream& inDevice)
{
	for (int i = 0;i < this->numVertex;i++)
	{
		for (int j = 0;j < this->numVertex;j++)
		{
			inDevice >> this->matrix[i][j];
		}
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