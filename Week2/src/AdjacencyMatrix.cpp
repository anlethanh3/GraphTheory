#include "AdjacencyMatrix.h"
#include <fstream>

AdjacencyMatrix::AdjacencyMatrix()
{
	this->type = 1;
}

AdjacencyMatrix::AdjacencyMatrix(const int& n)
{
	this->type = 1;
	this->n = n;
	this->matrix = new int*[this->n];
	for(int i = 0; i < this->n; i++)
	{
		this->matrix[i] = new int[this->n];
		for(int j = 0; j < this->n; j++)
		{
			this->matrix[i][j] = 0;
		}
	}
}

AdjacencyMatrix::~AdjacencyMatrix()
{
	for(int i=0; i<this->n;i++)
	{
		delete []this->matrix[i];
		this->matrix[i] = NULL;
	}
	delete []this->matrix;
	this->matrix = NULL;
	this->n = 0;
}

int AdjacencyMatrix::CountEdges()
{
	int sum = 0;
	for(int i = 0; i < this->n; i++)
	{
		for(int j = i+1; j < this->n; j++)
		{
			sum += this->matrix[i][j];
		}
	}
	return sum;
}

void 	AdjacencyMatrix::GetDegrees(int*& degrees)
{
	int degree;
	degrees = new int[this->n];
	for(int i = 0; i < this->n; i++)
	{
		degree = 0;
		for(int j = 0; j < this->n; j++)
		{
			degree += this->matrix[i][j];
		}
		degrees[i] = degree;
	}
}

int AdjacencyMatrix::GetTypeOfGraph()
{
	int result[3] 	= {0,0,0};
	int* degrees; 
	this->GetDegrees(degrees);
	for(int i = 0; i < this->n; i++)
	{
		if(degrees[i] == this->n - 1)
		{
			result[0]++;
		}
		else if(degrees[i] == 2)
		{
			result[1]++;
		}
		else if(degrees[i] == 1)
		{
			result[2]++;
		}
	}
	delete []degrees;
	degrees = NULL;
	if(result[0] == this->n)
	{
		return 1;
	}
	else if(result[1] == this->n)
	{
		return 2;
	}
	else if(result[0] == 1 && result[2] == this->n-1)
	{
		return 3;
	}
	return 0;
}

int AdjacencyMatrix::GetType()
{
	return this->type;
}

int** AdjacencyMatrix::GetMatrix()
{
	return this->matrix;
}

int AdjacencyMatrix::GetNumVertex()
{
	return this->n;
}
void AdjacencyMatrix::SetPath(int edge1, int edge2, bool hasPath)
{
	if(edge1 < this->n && edge2 < this->n)
	{
		this->matrix[edge1][edge2] = hasPath;
	}
}

void AdjacencyMatrix::ReadInput(char* file)
{
	std::fstream fs;
	fs.open(file, std::fstream::in);
	fs >> this->n;
	this->matrix = new int*[this->n];
	for(int i = 0; i < this->n; i++)
	{
		this->matrix[i] = new int[this->n];
		for(int j = 0; j < this->n; j++)
		{
			fs >> this->matrix[i][j];
		}
	}
	fs.close();
}

void AdjacencyMatrix::PrintOutput(char* file)
{
	std::fstream fs;
	fs.open(file, std::fstream::out);
	fs << this->n << std::endl;
	for(int i = 0; i < this->n; i++)
	{
		for(int j = 0; j < this->n; j++)
		{
			fs << this->matrix[i][j] <<" ";
		}
		fs << std::endl;
	}
}