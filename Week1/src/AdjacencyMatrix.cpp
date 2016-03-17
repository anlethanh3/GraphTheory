#include "AdjacencyMatrix.h"
#include <iostream>
#include <fstream>

AdjacencyMatrix::AdjacencyMatrix()
{
	this->type = 1;
}

AdjacencyMatrix::~AdjacencyMatrix()
{
	
}

int AdjacencyMatrix::CountEdges()
{
	return 0;
}

void 	AdjacencyMatrix::GetDegrees(int*& degrees)
{
}

int AdjacencyMatrix::GetTypeOfGraph()
{
	return 0;
}

void AdjacencyMatrix::ReadInput(char* file)
{
	std::fstream fs;
	fs.open(file, std::fstream::in);
	fs >> this->n;
	this->matrix = new bool*[this->n];
	for(int i = 0; i < this->n; i++)
	{
		this->matrix[i] = new bool[this->n];
		for(int j = 0; j < this->n; j++)
		{
			fs >> this->matrix[i][j];
		}
	}
	fs.close();
}

void AdjacencyMatrix::PrintOutput(char* file)
{
	
}