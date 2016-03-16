#ifndef 	_ADJACENCYGRAPH_H_
#define _ADJACENCYGRAPH_H_

class AdjacencyGraph
{
	protected:
		int type;
	public:
		AdjacencyGraph();
		~AdjacencyGraph();
		
		virtual int 		CountEdges() 				= 0;
		virtual char* 	PrintDegree()				= 0;
		virtual int 		TypeOfGraph() 				= 0;
		
		virtual void 	ReadInput(char* file) 	= 0;
		virtual void 	PrintOutput(char* file) 	= 0;
};

#endif