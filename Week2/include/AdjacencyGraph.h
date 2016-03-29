#ifndef  _ADJACENCYGRAPH_H_
#define _ADJACENCYGRAPH_H_

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
		virtual int 		GetType()								= 0;
		
		virtual void 	SetPath(int edge1, int edge2, bool hasPath) = 0;
		
		virtual void 	ReadInput(char* file) 		= 0;
		virtual void 	PrintOutput(char* file) 		= 0;
};

#endif