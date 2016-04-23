#ifndef _SVERTEX_H_
#define _SVERTEX_H_

struct SVertex
{
	int value;
	int index;
	SVertex()
	{
		value = 0;
		index = 0;
	}
	bool operator < (const SVertex& vertex)
	{
		return value < vertex.value;
	}
	bool operator >= (const SVertex& vertex)
	{
		return value >= vertex.value;
	}
};

#endif