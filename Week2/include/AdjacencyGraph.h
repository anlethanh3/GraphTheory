#ifndef  _ADJACENCYGRAPH_H_
#define _ADJACENCYGRAPH_H_

#include "CGraph.h"

class AdjacencyGraph
{
	protected:
		int type;
	public:
		AdjacencyGraph();
		virtual ~AdjacencyGraph();
		
		virtual int 		CountEdges() 						= 0;
		virtual void 	GetDegrees(int*& degrees)	= 0;
		virtual int 		GetTypeOfGraph() 				= 0;
		
		virtual void 	ConvertMatrix(const CGraph& graph) = 0;
		
		virtual void 	ReadInput(char* file) 		= 0;
		virtual void 	PrintOutput(char* file) 		= 0;
};

#endif