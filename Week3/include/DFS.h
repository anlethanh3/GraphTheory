#ifndef _DFS_H_
#define _DFS_H_

class DFS
{
	private:
		int* labels;
		int* previous;
		int size;
	public:
		DFS();
		DFS(const int& size);
		~DFS();
		
		void 	Run(int** matrix, int size, int start);
};

#endif