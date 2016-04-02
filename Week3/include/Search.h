#ifndef _SEARCH_H_
#define _SEARCH_H_

class Search
{
	protected:
		bool* labels;
		int* previous;
		int size;
	public:
		Search();
		Search(const int& size);
		virtual ~Search();
		
		bool 	GetLabel(int index);
		int	GetPrevious(int index);
		
		virtual void Run(int** matrix, int size, int start) = 0;
};

#endif