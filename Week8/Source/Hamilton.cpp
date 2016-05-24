#include "Hamilton.h"
#include <vector>
#include <iostream>

Hamilton::Hamilton()
{
	this->havePath = -1;
	this->cost = 0;
}

Hamilton::~Hamilton()
{
	this->havePath = -1;
	this->cost = -1;
	this->path.clear();
}

void Hamilton::Generator(int** matrix, std::vector<int> arrays)
{
	if (arrays.size() <= 0)
	{
		this->havePath = 1;
		return;
	}
	for (int j = 0; j < arrays.size(); j++)
	{
		int next = arrays[j];
		int pre = path[path.size() - 1];
		if (matrix[pre][next] > 0)
		{
			path.push_back(arrays[j]);
			cost += matrix[pre][next];
			arrays.erase(arrays.begin() + j);
			Generator(matrix, arrays);
			if (this->havePath == 1)
			{
				return;
			}
			arrays.insert(arrays.begin() + j, next);
			cost -= matrix[pre][next];
			path.pop_back();
		}
	}
}

void Hamilton::Run(int** matrix, int size, int start, bool isCycle)
{
	this->havePath = -1;
	std::vector<int> arrays;
	for (int i = size - 1; i >= 0; i--)
	{
		arrays.push_back(i);
	}
	path.push_back(start);
	arrays.erase(arrays.begin() + size - start - 1);

	Generator(matrix, arrays);

	if (this->havePath == 1 && isCycle == true)
	{
		int pre = path[path.size() - 1];
		if (matrix[pre][start] > 0)
		{
			this->path.push_back(start);
			this->cost += matrix[pre][start];
		}
		else
		{
			this->havePath = -1;
			this->cost = 0;
			this->path.clear();
		}
	}
}

void Hamilton::Write(std::ostream& outDevice)
{
	if (this->havePath == 1)
	{
		outDevice << this->cost << std::endl;
		for (int i = 0; i < this->path.size(); i++)
		{
			outDevice << this->path[i] << " ";
		}
	}
	else
	{
		outDevice << "NULL";
	}
}