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
	std::fstream fs;
	int* degrees;
	fs.open(file, std::fstream::out);
	fs << this->CountEdges() << std::endl;
	this->GetDegrees(degrees);
	for(int i=0; i < this->n; i++)
	{
		fs << degrees[i] << " ";
	}
	fs << std::endl;
	fs << this->GetTypeOfGraph();
	fs.close();
	delete []degrees;
	degrees = NULL;
}