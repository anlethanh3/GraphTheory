#ifndef  _BFS_H_
#define _BFS_H_

class BFS
{
	private:
		int* labels;
		int* previous;
		int size;
	public:
		BFS();
		~BFS();
		BFS(const int& size);
		
		void Run(int** matrix, int size, int start, int goal);
		void PrintPath(CListPoint* points, int start, int goal, char* file);
};

#endif