#ifndef  _CMATRIX_H_
#define _CMATRIX_H_

#include <iostream>

class CMatrix
{
	private:
		int size;
		int** weights;
	public:
		CMatrix();
		CMatrix(const int& size);
		~CMatrix();
		
		int GetSize();
		int GetValue(int i, int j);
		
		friend std::istream& 	operator >> (std::istream& inDevice, CMatrix& matrix);
		friend std::ostream&	 operator << (std::ostream& outDevice, const CMatrix& matrix);
};
#endif