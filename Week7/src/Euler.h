#ifndef _EULER_H_
#define _EULER_H_

#include <vector>
#include <iostream>

class Euler
{
private:
	int havePath;
	std::vector<int> path;
public:
	Euler();
	~Euler();

	bool IsBridgeEdge(int** matrix, int size, int begin, int end, int numConnect);
	void Run(int** matrix, int size, int numEdge);
	void Write(std::ostream& outDevice);
};

#endif