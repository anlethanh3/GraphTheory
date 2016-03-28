#include "CMatrix.h"

CMatrix::CMatrix()
{
}

CMatrix::CMatrix(const int& size)
{
	this->size = size;
	this->weights = new int*[this->size];
	for(int i=0; i < this->size; i++)
	{
		this->weights[i] = new int[this->size];
	}
}

CMatrix::~CMatrix()
{
	for(int i=0; i < this->size; i++)
	{
		delete[] this->weights[i];
	}
	delete[] this->weights;
	this->weights = NULL;
	this->size = 0;
}

int CMatrix::GetSize()
{
	return this->size;
}

int CMatrix::GetValue(int i, int j)
{
	return this->weights[i][j];
}

std::istream& operator >> (std::istream& inDevice, CMatrix& matrix)
{
	for(int i=0; i < matrix.size; i++)
	{
		for(int j=0; j < matrix.size; j++)
		{
			inDevice >> matrix.weights[i][j];
		}
	}
	return inDevice;
}

std::ostream& operator << (std::ostream& outDevice, const CMatrix& matrix)
{
	outDevice << matrix.size << std::endl;
	for(int i=0; i < matrix.size; i++)
	{
		for(int j=0; j < matrix.size; j++)
		{
			outDevice << matrix.weights[i][j] << " ";
		}
		outDevice << std::endl;
	}
	return outDevice;
}