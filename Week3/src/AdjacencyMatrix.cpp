#include "AdjacencyMatrix.h"
#include <fstream>

AdjacencyMatrix::AdjacencyMatrix()
{
	this->type = 1;
}

AdjacencyMatrix::AdjacencyMatrix(const int& size)
{
	this->type = 1;
	this->size = size;
	this->matrix = new int*[this->size];
	for(int i = 0; i < this->size; i++)
	{
		this->matrix[i] = new int[this->size];
		for(int j = 0; j < this->size; j++)
		{
			this->matrix[i][j] = 0;
		}
	}
}

AdjacencyMatrix::~AdjacencyMatrix()
{
	for(int i=0; i<this->size;i++)
	{
		delete []this->matrix[i];
		this->matrix[i] = NULL;
	}
	delete []this->matrix;
	this->matrix = NULL;
	this->size = 0;
}

int AdjacencyMatrix::GetType()
{
	return this->type;
}

int** AdjacencyMatrix::GetMatrix()
{
	return this->matrix;
}

void AdjacencyMatrix::Read(std::istream& inDevice)
{
	for(int i = 0; i < this->size; i++)
	{
		for(int j = 0; j < this->size; j++)
		{
			inDevice >> this->matrix[i][j];
		}
	}
}

void AdjacencyMatrix::Write(std::ostream& outDevice)
{
	outDevice << this->size << std::endl;
	for(int i = 0; i < this->size; i++)
	{
		for(int j = 0; j < this->size; j++)
		{
			outDevice << this->matrix[i][j] <<" ";
		}
		outDevice << std::endl;
	}
}