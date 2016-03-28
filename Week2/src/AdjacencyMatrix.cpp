#include "AdjacencyMatrix.h"
#include <fstream>
#include <iostream>
#include "CQueue.h"
#include "CListPoint.h"

AdjacencyMatrix::AdjacencyMatrix()
{
	this->type = 1;
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

void 	AdjacencyMatrix::ConvertMatrix(const CGraph& graph)
{
	int m = graph.matrix->GetSize();
	CListPoint* points = new CListPoint();
	for(int i=0; i < m; i++)
	{
		for(int j=0; j < m; j++)
		{
			if(graph.matrix->GetValue(i,j) == 0)
			{
				SPoint* point = new SPoint();
				point->x = i;
				point->y = j;
				points->Add(point);
			}
		}
	}
	this->n = points->GetLength();
	this->matrix = new bool*[this->n];
	for(int i = 0; i < this->n; i++)
	{
		this->matrix[i] = new bool[this->n];
		for(int j = 0; j < this->n; j++)
		{
			this->matrix[i][j] = 0;
		}
	}
	int k = -1;
	SPoint p;
	SPoint* point;
	SPoint* arrPoint =  new SPoint[4];
	for(int i=0; i < this->n; i++)
	{
		point = points->GetPoint(i);
		
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
			if(graph.matrix->GetValue(arrPoint[j].x, arrPoint[j].y) == 0)
			{
				k = points->GetIndexOf(&arrPoint[j]);
				if(k != -1)
				{
					this->matrix[i][k] = 1;
					this->matrix[k][i] = 1;
				}
			}
		}
	}
	delete[] arrPoint;
	arrPoint = NULL;
	point = NULL;
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
	// std::fstream fs;
	// int* degrees;
	// fs.open(file, std::fstream::out);
	// fs << this->CountEdges() << std::endl;
	// this->GetDegrees(degrees);
	// for(int i=0; i < this->n; i++)
	// {
		// fs << degrees[i] << " ";
	// }
	// fs << std::endl;
	// fs << this->GetTypeOfGraph();
	// fs.close();
	// delete []degrees;
	// degrees = NULL;
	
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