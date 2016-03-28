#ifndef  _CGRAPH_H_
#define _CGRAPH_H_

#include <iostream>
#include "CMatrix.h"
#include "SPoint.h"

class CGraph
{
	public:
		CMatrix* matrix;
		SPoint start;
		SPoint goal;
	public:
		CGraph();
		~CGraph();
		
		friend std::istream& operator >> (std::istream& inDevice, CGraph& graph);
		friend std::ostream& operator << (std::ostream& outDevice, const CGraph& graph);
};

#endif