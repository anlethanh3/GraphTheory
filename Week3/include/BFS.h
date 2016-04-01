#ifndef _BFS_H_
#define _BFS_H_

#include "Search.h"

class BFS : public Search
{
	public:
		BFS();
		BFS(const int& size);
		~BFS();
		
		void Run(int** matrix, int size, int start);
};

#endif