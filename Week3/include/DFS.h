#ifndef _DFS_H_
#define _DFS_H_

#include "Search.h"

class DFS : public Search
{
	public:
		DFS();
		DFS(const int& size);
		~DFS();
		
		void 	Run(int** matrix, int size, int start);
};

#endif