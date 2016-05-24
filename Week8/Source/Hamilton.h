#ifndef _HAMILTON_H_
#define _HAMILTON_H_

#include <vector>
#include <iostream>

class Hamilton
{
private:
	int havePath;
	int cost;
	std::vector<int> path;
public:
	Hamilton();
	~Hamilton();

	void Generator(int** matrix, std::vector<int> arrays);
	void Run(int** matrix, int size, int start, bool isCycle);
	void Write(std::ostream& outDevice);
};

#endif