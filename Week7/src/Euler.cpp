#include "Euler.h"
#include <vector>
#include <iostream>

Euler::Euler()
{
	this->havePath = -1;
}


Euler::~Euler()
{
	this->havePath = -1;
	this->path.clear();
}

bool Euler::IsBridgeEdge(int** matrix, int size, int begin, int end, int numConnect)
{
	int* label = new int[size];
	for (int i = 0;i < size;i++)
	{
		label[i] = i;
	}
	matrix[begin][end] = 0;
	matrix[end][begin] = 0;
	int numConnected = size;
	for (int i = 0;i < size;i++)
	{
		for (int j = 0;j < size;j++)
		{
			if (matrix[i][j] == 1)
			{
				int min = label[i] < label[j] ? label[i] : label[j];
				int max = label[i] > label[j] ? label[i] : label[j];
				if (min != max)
				{
					numConnected -= 1;
					for (int k = 0;k < size;k++)
					{
						if (label[k] == max)
						{
							label[k] = min;
						}
					}
				}
			}
		}
	}
	matrix[begin][end] = 1;
	matrix[end][begin] = 1;
	delete[] label;
	if (numConnected == numConnect)
	{
		return false;
	}
	return true;
}

void Euler::Run(int** matrix, int size, int numEdge)
{
	std::vector<int> oddEdges;
	int* edges = new int[size];
	for (int i = 0;i < size;i++)
	{
		edges[i] = 0;
		for (int j = 0; j < size; j++)
		{
			if (matrix[i][j] == 1)
			{
				edges[i] += 1;
			}
		}
		if (edges[i] % 2 == 1)
		{
			oddEdges.push_back(i);
		}
	}
	if (oddEdges.size() == 2 || oddEdges.size() == 0)
	{
		this->havePath = 1;
		int start = 0;
		if (oddEdges.size() == 2)
		{
			start = oddEdges[1];
		}
		int numConnect = 1;
		path.push_back(start);
		while (numEdge > 0)
		{
			int pos = path[path.size() - 1];
			int bridgeIndex = -1;
			int notBridgeIndex = -1;
			for (int i = 0;i < size;i++)
			{
				if (matrix[pos][i] == 1)
				{
					if (IsBridgeEdge(matrix, size, pos, i, numConnect) == true)
					{
						bridgeIndex = i;
					}
					else 
					{
						notBridgeIndex = i;
						break;
					}
				}
			}
			if (notBridgeIndex != -1)
			{
				matrix[pos][notBridgeIndex] = 0;
				matrix[notBridgeIndex][pos] = 0;
				path.push_back(notBridgeIndex);
			}
			else
			{
				matrix[pos][bridgeIndex] = 0;
				matrix[bridgeIndex][pos] = 0;
				path.push_back(bridgeIndex);
				numConnect += 1;
			}
			numEdge -= 1;
		}
	}
	oddEdges.clear();
	delete[] edges;
	edges = NULL;
}

void Euler::Write(std::ostream& outDevice)
{
	outDevice << this->havePath << std::endl;
	for (int i = 0;i < this->path.size();i++)
	{
		outDevice << this->path[i] << " ";
	}
}