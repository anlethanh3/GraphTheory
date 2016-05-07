#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include <iostream>

class Dijkstra
{
private:
	bool* label;
	int* previous;
	int* value;
	int size;
public:
	Dijkstra();
	Dijkstra(const int& size);
	~Dijkstra();

	void Run(int** matrix, int size, int start, int goal);
	void Write(std::ostream& outDevices, int start, int goal);
};
#endif